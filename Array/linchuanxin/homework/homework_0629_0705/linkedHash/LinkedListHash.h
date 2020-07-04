//
// Created by LCX on 2020/7/3.
//

#ifndef ALGORITHM_C_LINKEDLISTHASH_H
#define ALGORITHM_C_LINKEDLISTHASH_H

#include <stdio.h>
#include <stdbool.h>
#define DataType int
#define Len 6

typedef struct _hash_node{
    DataType data;
    struct _hash_node *next;
}HashNode;


typedef struct _hash_table{
    HashNode *hashKey[Len];
}HashTable;

HashTable* init_HashTable();  //初始化
bool hash_addKey(HashTable* hashTable,DataType data);    //插入
bool hash_deleteKey(HashTable* hashTable,DataType data);  //删除
bool hash_modifyKey(HashTable* hashTable,DataType oldData,DataType newData);  //修改
HashNode* hash_lookup(HashTable *hashTable,DataType data);


#endif //ALGORITHM_C_LINKEDLISTHASH_H
