### BInder 机制

##### Linux 现有的所有进程间通信方式

* 管道：在创建时分配一个 页 大小的内存，缓存区大小有限
* 消息队列：信息复制两次（入队一次，出队一次），会造成 CPU 的消耗，不适合频繁或信息量大的通信
* 共享内存：无需复制，速度快，但是无法解决进程间同步问题，必须各个进程利用同步工具解决
* 套接字（socket）：传输效率低，主要用于网络和不同机器之间的传输
* 信号量：锁机制，主要用于防止某进程访问共享资源时，其他进程也访问该资源
* 信号：不适用于信息交换，更适用于进程中断控制，比如非法内存访问，杀死某个进程

**Q: android 为什么选择 binder 作为进程间通信机制 ？ ** 

* 性能角度：Binder 数据只 copy 一次，性能仅次于共享内存（不用 copy）
* 稳定性角度：Binder 基于 C/S 架构，实现简单，共享内存实现复杂必须解决死锁问题
* 安全角度：C/S 架构只暴露 Client 端，Server 会根据权限控制判断 UID/PID 是否满足访问权限，Linux 传统的通信方式只能通过上层协议来确保用户的安全性



#### Binder 原理

* Binder 通信采用 C/S 架构，从组件视角来说，包含 Client，Server，ServiceManager 以及 binder 驱动四个模块
  * ServiceManager 是整个 binder 的大管家，是 android 进程间通信机制 binder 的守护进程
  * Client 端和 Server 端通信前都要获取 ServiceManager 接口
  * binder 驱动位于内核空间（内核空间相对于所有进程来说是共享的），Client，Server，ServiceManager 彼此之间的通信都是通过与 binder 驱动进行交互的

<img src="/Users/fenglei/Documents/learning/source read/img/1593421688940.jpg" alt="1593421688940" style="zoom:50%;" />

* BpBinder 和 BBinder 都是 Android 中 binder 通信的代表
  * BpBinder 代表客户端通过 BpBinder.transact(); 来发送事务请求
  * BBinder 代表服务端通过 BBinder.onTransact(); 接收相应的事务

##### Binder 创建过程

* 创建 binder 在底层的调用链： open()  ->  _open()  ->  binder_open()，创建 binder 主要用到了四个函数
* binder_init 注册 misc 设备
* open 为用户空间的函数，_open() 是和 binder_open() 是内核中的函数
  * binder_proc 对象管理进程通信所需的各种信息，每打开 binder 启动都会创建一个 binder_poc 对象，并把它加入 binder_procs 链表中
  * binder_procs 是哈希链表，保存了所有的 binder_proc 队列，每次创建新的 binder_proc 都会加入 binder_procs 链表中
  * 该过程需要持有binder_main_lock同步锁
* binder_mmap 函数的作用是内核空间申请一块与用户空间虚拟内存相同大小的内存，然后在申请一个 page 大小的物理内存，最后把物理内存分别映射到内核空间和用户空间中，保证了用户空间和内核空间同步操作的功能，该过程需要持有binder_main_lock同步锁
* binder_ioctl 函数负责在两个进程间收发通信数据，该过程需要持有binder_main_lock同步锁，当无数据时是否锁，当有数据时持有锁

##### Binder 通信过程

* 通过 binder_mmap 把虚拟进程地址空间和虚拟内核地址空间都映射到同一块物理内存地址空间中，当 Client 端与 Server 端发送数据时，Client 先从自己的进程空间把数据 copy 到内核空间，而 Server 端与内核共享数据，不再需要 copy 数据，而是通过内存地址空间的偏移量获取内存地址，整个过程只发生一次内存 copy

<img src="/Users/fenglei/Documents/learning/source read/img/WechatIMG3211.png" alt="WechatIMG3211" style="zoom:50%;" />

##### ServiceManager 启动流程

参考源码路径

```c++
framework/native/cmds/servicemanager/
  - service_manager.c
```

* 启动流程可以分为三个阶段：1.打开 binder 驱动：binder_open  2.注册称为 binder 服务的大管家  3.进入无线循环，处理 client 端发来的请求
  * 打开 binder 驱动，调用 mmap 方法分配内存映射空间
  * 通知 binder 驱动称为大管家
  * 进入循环状态，等待 client 请求
  * 注册服务时，根据服务名称查询是否有相同服务注册，在重新注册之前需要移除之前注册信息
  * 当 binder 所在进程死亡后，通知 ServiceManager

```c++

int main(int argc, char** argv)
{
    struct binder_state *bs;
    union selinux_callback cb;
    char *driver;

		// 打开 binder 驱动
    bs = binder_open(driver, 128*1024);
  	// 称为上下文管理者
    if (binder_become_context_manager(bs)) {
        ALOGE("cannot become context manager (%s)\n", strerror(errno));
        return -1;
    }
		
  	// 进入无线循环
  	binder_loop(bs, svcmgr_handler);

    return 0;
}
```

* ServieManager 的主要工作时注册服务和查询服务
  * 检查权限是否满足
  * 服务检索，根据服务名来匹配服务
  * 释放服务，当查询到已经同名的服务，先清理该服务信息，再将当前的服务加入到服务列表 svclist 中

1. 注册服务 记录服务名和 各种信息保存到 scvlist 列表

```c++
int do_add_service(struct binder_state *bs, const uint16_t *s, size_t len, uint32_t handle,
                   uid_t uid, int allow_isolated, uint32_t dumpsys_priority, pid_t spid, const char* sid) {
    struct svcinfo *si;

    if (!handle || (len == 0) || (len > 127))
        return -1;
		// 权限检查
    if (!svc_can_register(s, len, spid, sid, uid)) {
        ALOGE("add_service('%s',%x) uid=%d - PERMISSION DENIED\n",
             str8(s, len), handle, uid);
        return -1;
    }
		// 查询服务
    si = find_svc(s, len);
    if (si) {
        if (si->handle) {
            ALOGE("add_service('%s',%x) uid=%d - ALREADY REGISTERED, OVERRIDE\n",
                 str8(s, len), handle, uid);
          	 	// 服务已存在，释放服务
            svcinfo_death(bs, si);
        }
        si->handle = handle;
    } else {
      	// 新增服务分配内存
        si = malloc(sizeof(*si) + (len + 1) * sizeof(uint16_t));
        if (!si) {
            ALOGE("add_service('%s',%x) uid=%d - OUT OF MEMORY\n",
                 str8(s, len), handle, uid);
            return -1;
        }
      	// 拷贝服务信息
        si->handle = handle;
        si->len = len;
        memcpy(si->name, s, (len + 1) * sizeof(uint16_t));
        si->name[len] = '\0';
        si->death.func = (void*) svcinfo_death;
        si->death.ptr = si;
        si->allow_isolated = allow_isolated;
        si->dumpsys_priority = dumpsys_priority;
        // svclist 保存所有已经注册的服务
        si->next = svclist;
        svclist = si;
    }
		// TODO 这两句啥意思看不懂.. 
    binder_acquire(bs, handle);
    binder_link_to_death(bs, handle, &si->death);
    return 0;
}
```

2. 查询服务，根据服务名查询相应的信息

```c++
uint32_t do_find_service(const uint16_t *s, size_t len, uid_t uid, pid_t spid, const char* sid)
{		
  	// 查询服务
    struct svcinfo *si = find_svc(s, len);

    if (!si || !si->handle) {
        return 0;
    }

    if (!si->allow_isolated) {
       	// 如果此服务不允许从独立进程进行访问，检查uid是否被隔离
        uid_t appid = uid % AID_USER;
        if (appid >= AID_ISOLATED_START && appid <= AID_ISOLATED_END) {
            return 0;
        }
    }
		// 服务是否满足条件
    if (!svc_can_find(s, len, spid, sid, uid)) {
        return 0;
    }
    return si->handle;
}
```

