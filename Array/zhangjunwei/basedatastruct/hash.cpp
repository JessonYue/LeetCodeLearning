//
// Created by 张俊伟 on 2020/6/26.
//

#define DataType int
#define LEN 10  //hash table 的容量
typedef struct hashNode{
    bool isNull;//标示位 用于检测该位置是否使用了，检测冲突  false未使用  true已使用
    DataType value;//存储的数值
}HashTable;

HashTable hashTable[LEN];
//初始化 hastTable
void hashtable_init();
//hash 函数
static int get_hash_address(DataType key);
//在合理范围内查找 hash address
static int find(DataType key);
//插入数据
bool hashtable_insert(DataType key);
//删除  success return true or failed false
bool hashtable_delete(DataType key);

void hashtable_init(){
    for (int i = 0; i < LEN; ++i) {
        hashTable[i].isNull = false;
    }
}

//hash 函数
static int get_hash_address(DataType key){
    return key*3%7;
}
//在合理范围内查找 hash address
static int find(DataType key){
    int addr = get_hash_address(key);
    while (!(hashTable[addr].isNull && hashTable[addr].value == key) && addr<LEN)
        addr++;//没有找到 向下一个位置查找
    if (addr==LEN)return -1;
    return addr;//返回查找到的位置
}
//插入数据
bool hashtable_insert(DataType key){
    int addr = get_hash_address(key);
    if (hashTable[addr].isNull== false){//位置未使用
        hashTable[addr].isNull = true;
        hashTable[addr].value = key;
    } else{
        while (hashTable[addr].isNull && addr<LEN){//位置已占用 数组中还有容量时 向后填充
            addr++;
        }
        if (addr==LEN)return false;//没有多余空间添加数据
        hashTable[addr].isNull = true;
        hashTable[addr].value = key;
    }
    return true;
}
//删除  success return true or failed false
bool hashtable_delete(DataType key){
    int addr = find(key);
    if (addr==-1)return false;//要删除的数据不存在于 hashtable中
    hashTable[addr].isNull = false;
    hashTable[addr].value = -1;
    return true;
}

