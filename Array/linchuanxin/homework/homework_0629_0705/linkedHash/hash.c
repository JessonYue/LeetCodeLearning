//
// Created by LCX on 2020/6/27.
//

#include <stdio.h>

#define DataType int
#define True 1
#define Len 10

typedef struct HashNode{
    DataType data;
    int isNull;
}HashTable;

HashTable hashTable[Len];

void initHashTable();
int getHashAddress(DataType key);
int insert(DataType key);
int find(DataType key);


void initHashTable()
{
    int i;
    for (i = 0; i < Len; ++i) {
        hashTable[i].isNull = True;   //初始化状态都为true为空
    }
}

int getHashAddress(DataType key)
{
    return key*3%7;
}


int insert(DataType key)
{
    int address = getHashAddress(key);
    //判断hash冲突
    //1.没有冲突
    if(hashTable[address].isNull == True)
    {
        hashTable[address].data = key;
        hashTable[address].isNull = 0;   //标记占位
    }
    //2.冲突
    else
    {
        while (hashTable[address].isNull == 0 && address < Len)
        {
            address++;
        }
        if (address == Len)
            return -1;
        hashTable[address].data = key;
        hashTable[address].isNull = 0;
    }
    return 0;
}
//在合理的范围内 通过key找到address
int find(DataType key)
{
    int address = getHashAddress(key);
    while (!(hashTable[address].data == key && address < Len))
    {
        address++;
    }
    if(address == Len)
    {
        return -1;
    }

    return address;

}

int main()
{
    initHashTable();
    printf("%d\n",insert(1));   //3
    printf("%d\n",insert(2));   //6
    printf("%d\n",insert(3));   //2
    printf("%d\n",insert(4));   //5
    printf("%d\n",insert(5));  //1
    printf("%d\n",insert(6));  //4
    printf("%d\n",insert(7));  //0
    printf("%d\n",insert(8));  //7
    printf("%d\n",insert(9));  //8
    printf("%d\n",insert(10));  //9
    printf("---------------\n");
    printf("%d\n",find(2));

    return 0;
}