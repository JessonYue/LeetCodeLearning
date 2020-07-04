图有两个重要的点:

广度优先和深度优先(矩阵可以这么做)



hash可以节约查询时间

hashcode

一致性hash

hashtable

加密算法:md5 md4

产生原因:

​	n个数  数组中   取数  需要遍历

当不想遍历又想取数  就产生hash



散列函数  散列表   



hash产生原因是起平衡  : time  space



散列表:存放n个数的空间

散列函数:自己定义的函数,hash算法好,冲突就低



数学:求余法 折叠法

hash算法  hash散列函数



14  29  6  74  25  101  40

array[n]%n

0   1   2   3   4   5  6

hash冲突怎么解决    

最基本的做法

线性探测:数组的移位  看这个位置有没有这个数 如果空 后面有空 就放在这个地方

(开地址法)l链值地址法:数组加链表,不进行扩容,重复元素通过链表链接,可以一直链接下去



hash算法:样本空间的均衡性

查找通过hash值定位键值,然后链表中node需要遍历 瓶颈点  所以jdk改成了红黑树(高阶结构)  这就hash



设计hash

设计struct很重要

两种设计方式:基于数组和链表

1.hash函数

2.hash冲突



hashtable 就是hash



定长的集合  数组 



元素赋值

内存开辟

内存开辟   静态空间    hashtable[10]   数组自动开

如果是malloc 那么  就是 Hashtable*  hashtable



线性探测法           

链地址法





HashTable* hashTable = static_cast<HashTable *>(malloc(sizeof(HashNode)));
    if(hashTable == nullptr)
        return NULL;
    memset(hashTable,0,sizeof(hashTable));     //清除脏数据  如果是clloc就不用此写法 因为会自动清除脏数据



链表头不放数据

所以路哥代码中才会  hNode = ht->hashKey[data%6]->next;

增加一个next





指针需要初始化 不然取不出来数据

 HashNode* hNode;
 hNode = static_cast<HashNode *>(malloc(sizeof(HashNode)));





1.队列    栈和堆使用数组 没有用链表 用链表实现

2.hash 补充链表实现