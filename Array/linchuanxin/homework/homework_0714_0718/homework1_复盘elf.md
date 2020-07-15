### ELF 文件类型

ELF文件可以被标记为以下几种类型：

- ET_NONE: 未知类型。该标记的文件类型不确定或者还未定义。
- ET_REL:　重定位文件（目标文件, xxx.o ）。可重定位文件是还未链接到可执行文件的独立代码，即编译后的 .o 文件。
- ET_EXEC: 可执行文件。这类文件也成为程序，是一个进程开始的入口。
- ET_DYN:　共享目标文件，即动态链接文件，.so 文件。在程序运行时被装载并链接到程序的进程镜像中。
- ET_CORE: 核心文件。在程序崩溃或者进程传递了一个SIGSEGV信号（分段违规）时，会在核心文件中记录整个进程的镜像信息。可以使用GDB读取这类文件来辅助调试并查找程序崩溃的原因



### 整体结构

elf header-->elf文件头的位置是固定的
Segment Header Table -->elf程序头的描述是段的相关信息    (段头表)
.init
.text
.rodata
.data
.symtab   符号表
.line
.strtab 字符串表
Section Header Table--->elf节头表描述的是节区的信息
**动态用段      静态用节**



### 段和节

程序**真正运行加载**是**段**  提高执行效率

**静态分析**的时候 看的是**节**

-a 当前相关信息
-h 头
-l 段
-S 节头表信息
-s符号表 相关符号信息
-r -d -V -A -I暂时不管



### 三大结构

头
节
程序头（段）

Magic   魔术
class   elf32
...
Entry point address  0x854c     偏移是0x854c    对于可执行程序是有意义  对静态和动态链接库没啥意义
Start of program headers   程序头的偏移  0x52
Start of section headers    节头表的偏移是8556
Flags   标识 默认是5
Size of this headers   头的大小52  byte
Size of program headers   程序头的大小32   一个程序头的大小是32  byte
Number of program headers   表象  有多少个程序头  程序头的数量  8个程序头
Size of section headers   节头表大小是 40 byte   一个是40byte
Number of section headers    表象  有多少个节头表  节头表的数量  有24个节
Section header string table index   节头的字符串 节的名称的索引  描述字符串表的索引   23

![image.png](https://gitee.com/andylinchuanxin/bookimagenew/raw/master/img/1.png)

### 节信息

节头起始偏移是8556 加上每一个节头表的大小是40byte
即
8556+40 * 23   得到结果地址指向字符串表---》（Section header string table index    23）

----------------》
Section Headers:    //节头表信息
[0]  - [23]代表有24个节
.interp
.dynsym   动态链接的**符号表**
.dynstr    动态链接的**字符串**
.hash
.rel.dyn   动态链接的**重定位**
.rel.plt    plt过程**连接表的重定位**
.plt
.text          **存放代码**     重点掌握
.note.android.ide
.ARM.exidx
.rodata     只读的权限   只读操作
.ARM.extab
.fini_array
.init_array
.preinit_array
.dynamic    **动态链接的节区**
.got   **全局的偏移表**
.data   数据段 可以进行读写操作    **全局初始化 都会存放在这里data**      重点掌握
.bss    变量的统一的初始化    **未被初始化的变量会放在.bss中  进行统一的初始化**     重点掌握
.comment
.note.gnu.gold-ve
.ARM.attributes

**[23].shstrtab     比较特殊    .sh节头表缩写就是sh     .shstrtab包含所有节的信息和所有节的名称 就在此字符串表中**

![image.png](https://gitee.com/andylinchuanxin/bookimagenew/raw/master/img/2.png)



### 段信息

```
typedef struct {  
    Elf32_Word p_type;           //此数组元素描述的段的类型，或者如何解释此数组元素的信息。 
    Elf32_Off  p_offset;           //此成员给出从文件头到该段第一个字节的偏移
    Elf32_Addr p_vaddr;         //此成员给出段的第一个字节将被放到内存中的虚拟地址
    Elf32_Addr p_paddr;        //此成员仅用于与物理地址相关的系统中。System V忽略所有应用程序的物理地									址信息。
    Elf32_Word p_filesz;         //此成员给出段在文件映像中所占的字节数。可以为0。
    Elf32_Word p_memsz;     //此成员给出段在内存映像中占用的字节数。可以为0。
    Elf32_Word p_flags;         //此成员给出与段相关的标志。
    Elf32_Word p_align;        //此成员给出段在文件中和内存中如何对齐。
} Elf32_phdr;
```

参数说明:

```
(1) p_type表示当前描述的段的种类。常见有以下常数。
 
    #define PT_NULL    0  //空段
 
    #define PT_LOAD    1  //可装载段
 
    #define PT_DYNAMIC 2  //表示该段包含了用于动态连接器的信息
 
    #define PT_INTERP  3  //表示当前段指定了用于动态连接的程序解释器，通常是ld-linux.so
 
    #define PT_NOTE    4  //该段包含有专有的编译器信息
 
    #define PT_SHLIB   5  //该段包含有共享库
 
  
 
(2) p_offset给出了该段在二进制文件中的偏移量，单位为字节。
 
(3) p_vaddr给出了该段需要映射到进程虚拟地址空间中的位置。
 
(4) p_paddr在只支持物理寻址，不支持虚拟寻址的系统当中才使用。
 
(5) p_filesz给出了该段在二进制文件当中的长度，单位为字节。
 
(6) p_memsz给出了段在虚拟地址空间当中的长度，单位为字节。与p_filesz不等时会通过截断数据或者以0填充的方式处理。
 
(7) p_flags保存了标志信息，定义了该段的访问权限。有如下值
 
    #define PF_R        0x4     //该段可读
 
    #define PF_W       0x2     //该段可写
 
    #define PF_X        0x1     //该段可执行
 
(8) p_align指定了段在内存和二进制文件当中的对齐方式，即p_offset和p_vaddr必须是p_align的整数倍。
```

![image.png](https://gitee.com/andylinchuanxin/bookimagenew/raw/master/img/6.png)

![image.png](https://gitee.com/andylinchuanxin/bookimagenew/raw/master/img/7.png)

**LOAD才会加载到内存**中 所以是02和03段

02段中

**.interp开始**

到**.ARM.extab结束** 就是节头表中的[12]

![image.png](https://gitee.com/andylinchuanxin/bookimagenew/raw/master/img/9.png)



### 节头和程序头的关系

节头和程序头的关系，根据Flg来划分

段信息中:

02段都是以**A开头的权限**
03段都是以**W开头的权限** 

![image.png](https://gitee.com/andylinchuanxin/bookimagenew/raw/master/img/11.png)

![image.png](https://gitee.com/andylinchuanxin/bookimagenew/raw/master/img/12.png)

所以看出 两个load是根据权限来划分

其中,在段信息中

![image.png](https://gitee.com/andylinchuanxin/bookimagenew/raw/master/img/13.png)



### 段(segment)和节(section)混淆区分

wiki上对二者的解释:

```
The segments contain information that is needed for run time execution of the file, while sections contain important data for linking and relocation. Any byte in the entire file can be owned by one section at most, and orphan bytes can occur which are unowned by any section.
```

**一个段包含零个至多个节，一个elf文件包含零个或多个段**



二者的区别也体现在接下来的程序头和节头的概念中:

```
An ELF file has two views: the program header shows the segments used at run time, whereas the section header lists the set of sections of the binary.
```

程序头描述的是段的信息。程序头表是程序头列表，跟在 ELF 头的后面