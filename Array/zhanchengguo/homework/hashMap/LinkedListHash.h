//
// Created by Jesson on 2020/6/25.
//

#ifndef BASEDATASTRUCTURE_LINKEDLISTHASH_H
#define BASEDATASTRUCTURE_LINKEDLISTHASH_H

//按照JDK的规范来写代码
typedef struct _hash_node{
    int data;
    struct _hash_node *next;
}HashNode;

typedef struct _hash_table{
    HashNode* hashKey[6];
}HashTable;

#endif //BASEDATASTRUCTURE_LINKEDLISTHASH_H
