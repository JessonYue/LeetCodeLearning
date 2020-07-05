### MemoryFile 分析

##### MemoryFile 由来

* 由之前分析 binder 机制可知，binder 机制的本质是，ServiceManager 为进程在物理内存中开辟一个 page 大小的空间，并把这个空间的地址映射到进程区域和内核区域从而实现了进程间的通信，但是一个 page 大小的空间极为有限，使得不同进程传递的数据大小也极为有限，而 MemoryFile 主要是针对解决这个问题产生的
* 匿名共享内存是一种共享内存的机制，它利用了 mmap 函数将不同进程中的一段物理内存映射到各自进程的虚拟地址空间，从而实现了进程间的共享，它也可以通过 binder 进程间通信实现进程间共享
* MemoryFile 就是 android 提供的共享内存对外暴露的接口，可以通过 MemoryFile 来创建使用共享内存

##### MemoryFile 源码分析

* MemoryFile 对外暴露的方法有 4 个，创建 MemoryFile，销毁 MemoryFile，读文件，写文件

参考源码路径

```
android/os
  - MemoryFile.java
  - SharedMemory.java
```

* 创建 MemoryFile

```java
    /**
     分配一个新的匿名共享内存区域(ashmem)，共享内存区域默认是不可以被回收的
	   也就是说即使系统发现内存不足，需要清理空间时，也不能回收 ashmem
		 参数 1: 自定义的文件名称(不能为 null)
     参数 2: 开辟内存的大小
    **/
		public MemoryFile(String name, int length) throws IOException {
        try {
            // 在物理内存中开辟一块儿空间，猜测底层和 binder 类似也是用了 mmap 函数
            mSharedMemory = SharedMemory.create(name, length);
          	// 创建共享内存的读写映射
            mMapping = mSharedMemory.mapReadWrite();
        } catch (ErrnoException ex) {
            ex.rethrowAsIOException();
        }
    }

    
    public static @NonNull SharedMemory create(@Nullable String name, int size)
            throws ErrnoException {
        if (size <= 0) {
            throw new IllegalArgumentException("Size must be greater than zero");
        }
        // 创建共享内存
        return new SharedMemory(nCreate(name, size));
    }

    // 创建文件描述符(文件描述符是什么鬼？)
    private static native FileDescriptor nCreate(String name, int size) throws ErrnoException;


```

* 销毁 MemoryFile

```java
    public void close() {
      	// 取消文件映射
        deactivate();
      	// 关闭共享内存空间
        mSharedMemory.close();
    }
	
    // 调用这个方法从进程的空间取消映射内存文件，但是不关闭它
    void deactivate() {
        if (mMapping != null) {
            SharedMemory.unmap(mMapping);
            mMapping = null;
        }
    }
```

* 读文件

```java
    /**
      从匿名共享内存中读取文件
    	参数1: 匿名共享内存的映射控件
    	参数2: 内存文件的偏移量
    	参数3: 字节数组缓冲区的偏移量
    	参数4: 需要读取的大小
    	return: 读取的字节数
    */
		public int readBytes(byte[] buffer, int srcOffset, int destOffset, int count)
            throws IOException {
        beginAccess();
        try {
            // 将指针便宜到设置好的地方
            mMapping.position(srcOffset);
            // 从字节缓冲区读取数据
            mMapping.get(buffer, destOffset, count);
        } finally {
            // 这个不太懂？判断是否清楚了数据？
            endAccess();
        }
        return count;
    }


 // 在写和读之前都要加查文件描述符，目前不知道文件描述符是什么，推测想要访问某个匿名共享内存需要依赖文件描述符
 private void beginAccess() throws IOException {
        checkActive();
        if (mAllowPurging) {
            if (native_pin(mSharedMemory.getFileDescriptor(), true)) {
                throw new IOException("MemoryFile has been purged");
            }
        }
    }

    private void endAccess() throws IOException {
        if (mAllowPurging) {
            native_pin(mSharedMemory.getFileDescriptor(), false);
        }
    }

```

* 写文件

```java
/**
 将字节数据写入内存
 参数1: 匿名共享内存的映射控件
 参数2: 内存文件的偏移量
 参数3: 字节数组缓冲区的偏移量
 参数4: 需要读取的大小
*/
public void writeBytes(byte[] buffer, int srcOffset, int destOffset, int count)
        throws IOException {
    beginAccess();
    try {
      	 // 将指针便宜到设置好的地方
        mMapping.position(destOffset);
         // 在指定的位置写入数据
        mMapping.put(buffer, srcOffset, count);
    } finally {
        endAccess();
    }
}
```



##### Demo

* server

```java
/**
 * 作者：丰雷
 * 时间：2020/6/30:12:21 PM
 * 说明：
 */
public class MemoryService extends Service {

    private MemoryFile mMemoryFile = null;
    private final static String MEMORY_FILE_NAME = "fl_memory";
    private static final int SIZE_1M = 1024 * 1024;
    private static final int REPORT_MSG = 1;
		// 管理所有的 client
    RemoteCallbackList<IMemoryFileCallback> mCallbacks = new RemoteCallbackList<IMemoryFileCallback>(){
        @Override
        public void onCallbackDied (IMemoryFileCallback callback, Object cookie) {
            mCallbacks.beginBroadcast();
            mCallbacks.finishBroadcast();
            mCallbacks.unregister(callback);
        }
    };

    @Override
    public void onCreate () {
        super.onCreate();
        try {
            mMemoryFile = new MemoryFile(MEMORY_FILE_NAME,SIZE_1M);
        } catch (IOException e) {
            Log.e("MemoryService","onCreate(MemoryService.java:49)"+e);
            e.printStackTrace();
        }
    }

    @Nullable
    @Override
    public IBinder onBind (Intent intent) {
        return mStub;
    }

    @Override
    public int onStartCommand (Intent intent, int flags, int startId) {
        return START_NOT_STICKY;
    }

    @Override
    public void onDestroy () {
        super.onDestroy();
        mCallbacks.kill();
        mMemoryFile.close();
    }

    private final IMemoryFileService.Stub mStub = new IMemoryFileService.Stub() {
        @Override
        public void addCallback (IMemoryFileCallback callback) throws RemoteException {
            if (callback != null) {
                mCallbacks.register(callback);
                mHandler.sendEmptyMessage(REPORT_MSG);
            }
        }

        @Override
        public void removeCallback (IMemoryFileCallback callback) throws RemoteException {
            if (mCallbacks != null) mCallbacks.unregister(callback);
        }

        @Override
        public int readBytes (byte[] buffer, int srcOffset, int destOffset, int count) throws RemoteException {
            int ret = -1;
            if(mMemoryFile != null){
                try {
                    ret = mMemoryFile.readBytes(buffer, srcOffset, destOffset, count);
                } catch (IOException e) {
                    Log.e("MemoryService","readBytes(MemoryService.java:90)"+e);
                    e.printStackTrace();
                }
            }

            return ret;
        }

        @Override
        public void wirteBytes (byte[] buffer, int srcOffset, int destOffset, int count) throws RemoteException {
            if(mMemoryFile != null){
                try {
                    printByte(buffer, count);
                    mMemoryFile.writeBytes(buffer, srcOffset, destOffset, count);
                } catch (IOException e) {
                   Log.e("MemoryService","wirteBytes(MemoryService.java:105)"+e);;
                    e.printStackTrace();
                }
            }
        }

        @Override
        public int length () throws RemoteException {
            int len = 0;
            if(mMemoryFile != null){
                len = mMemoryFile.length();
            }
            return len;
        }

        @Override
        public void notifyFinish () throws RemoteException {
            mHandler.sendEmptyMessageDelayed(REPORT_MSG,2 * 1000);
        }
    };

    private Handler mHandler = new Handler(Objects.requireNonNull(Looper.myLooper())){
        @Override
        public void handleMessage (@NonNull Message msg) {
            switch (msg.what){
                case REPORT_MSG:
                    final int N = mCallbacks.beginBroadcast();
                    for (int i=0; i<N; i++) {
                        try {
                            mCallbacks.getBroadcastItem(i).onFrameAvaiable(0, mMemoryFile.length());
                        } catch (RemoteException e) {
                            // The RemoteCallbackList will take care of removing the dead object for us.
                           Log.e("MemoryService","handleMessage(MemoryService.java:115)"+e);
                        }
                    }
                    mCallbacks.finishBroadcast();
                    break;
            }
        }
    };

    private void printByte(byte[] r_buf, int len) {
        StringBuilder s = new StringBuilder();
        for(int i = 0; i < len; i++){
            s.append(r_buf[i]).append(",");
        }
       Log.e("MemoryService","printByte(MemoryService.java:147)"+s);
    }
}
```



* Client

```java
public class MainActivity extends AppCompatActivity {

    private IMemoryFileService mProxy;
    private boolean mIsBound = false;

    @Override
    protected void onCreate (Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        bindRemoteService();
    }

    private void bindRemoteService(){
        Intent intent = new Intent();
        intent.setAction("com.myaction.MemoryService");
        intent.setPackage("com.example.framewok.zmaster.ndk.memoryfileserver");
        boolean b = bindService(intent, mConnection, Context.BIND_AUTO_CREATE);
        Log.e("MainActivity","bindRemoteService(MainActivity.java:36)"+b);
    }


    private ServiceConnection mConnection = new ServiceConnection() {
        @Override
        public void onServiceConnected (ComponentName name, IBinder service) {
            Log.e("MainActivity", "onServiceConnected(MainActivity.java:30)" + "IMemoryFileService connected");
            mProxy = IMemoryFileService.Stub.asInterface(service);
            try {
                mProxy.addCallback(mMemoryFileCallback);
                Log.e("MainActivity", "onServiceConnected(MainActivity.java:35)" + mProxy.length());
            } catch (RemoteException e) {
                e.printStackTrace();
                Log.e("MainActivity", "onServiceConnected(MainActivity.java:38)" + e);
            }
            mIsBound = true;
            readWrite();
        }

        @Override
        public void onServiceDisconnected (ComponentName name) {
            Log.e("MainActivity", "onServiceDisconnected(MainActivity.java:44)" + "IMemoryFileService disconnected");
            mIsBound = false;
            try {
                mProxy.removeCallback(mMemoryFileCallback);
                mProxy = null;
            } catch (RemoteException e) {
                e.printStackTrace();
                Log.e("MainActivity", "onServiceDisconnected(MainActivity.java:51)" + e);
            }
        }
    };


    private IMemoryFileCallback mMemoryFileCallback = new IMemoryFileCallback.Stub() {
        @Override
        public void onFrameAvaiable (int format, int size) throws RemoteException {
            mProxy.notifyFinish();
        }
    };


    private void readWrite () {
        if (!mIsBound) return;
        byte[] write_buffer = new byte[16];
        byte[] read_buffer = new byte[16];

        for (int i = 0; i < write_buffer.length; i++) {
            write_buffer[i] = (byte) i;
        }

        try {
            mProxy.wirteBytes(write_buffer,0,0,16);
            mProxy.readBytes(read_buffer,0,0,16);
            printByte(read_buffer);
        } catch (RemoteException e) {
            e.printStackTrace();
            Log.e("MainActivity","readWrite(MainActivity.java:82)"+e);
        }
    }

    private void printByte (byte[] read_buffer) {
        StringBuilder s = new StringBuilder();
        for (byte b : read_buffer) {
            s.append(b).append(",");
        }
        Log.e("MainActivity","printByte(MainActivity.java:91)"+s);
    }

    @Override
    protected void onDestroy () {
        super.onDestroy();
        if (mConnection!=null) unbindService(mConnection);
    }

    public void notifyFinish (View view) {
        if(mProxy != null){
            try {
                mProxy.removeCallback(mMemoryFileCallback);
            } catch (RemoteException e) {
                e.printStackTrace();
            }
        }
    }
}
```

可以看到 MemoryFile 的 java 层实现比较简单，具体实现在 native 层