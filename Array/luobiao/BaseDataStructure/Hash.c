//
// Created by Jesson on 2020/6/24.
//
#include<stdio.h>
#define DataType int
#define Len 10
#define True 1

typedef struct HashNode
{
    DataType data;    //存储值
    int isNull;       //标志该位置是否已被填充,检测是否有冲突
}HashTable;


HashTable hashTable[Len];
/*对hash表进行初始化 1。元素的赋值 2。内存开辟*/
void initHashTable()
{
    int i;
    for(i = 0; i<Len; i++)
    {
        //初始状态为空
        hashTable[i].isNull = True;
    }

//    HashTable* hashTable1 =
}
/*Hash函数*/
int getHashAddress(DataType key)
{
    return key *3 % 7;
}

//Java 如何判断2歌对象是同一个 hashcode + equals

/*注意去解决hash冲突的问题*/
int insert(DataType key)
{
    int address = getHashAddress(key);
    //没有发生冲突
    if(hashTable[address].isNull == True || hashTable[address].data == key)
    {
        hashTable[address].data = key;
        hashTable[address].isNull = 0;
        printf("insert1   key:%d\t address:%d\n", key,address);
    }
    else    //当发生冲突的时候
    {

        while(hashTable[address].isNull == 0 && address<Len)
        {
            address++;          //采用线性探测法，步长为1
        }
        if(address == Len)      //Hash表发生溢出
            return -1;
        hashTable[address].data = key;
        hashTable[address].isNull = 0;
        printf("insert2   key:%d\t address:%d\n", key,address);
    }

    return 0;
}
//在合理的范围内 通过key找到address
int find(DataType key)
{
    int address = getHashAddress(key);
    while( !(hashTable[address].isNull == 0 && hashTable[address].data == key && address<Len))
    {
        address++;
    }

    if( address == Len)
    {
        address = -1;
    }

    return address;
}


int main(int argc, char *argv[])
{
    int key[]={7,8,30,11,18,9,14,7};
    int i;
    initHashTable();

    for(i = 0; i<8; i++)
    {
        int success = insert(key[i]);
        printf("key:%d\t success:%d\n", key[i],success);
    }

    for(i = 0; i<8; i++)
    {
        int address;
        address = find(key[i]);
        printf("key:%d\t address:%d\n", key[i],address);
    }

    return 0;
}
