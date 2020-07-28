//
// Created by Jesson on 2020/6/25.
//

#include <cstdlib>
#include <cstring>
#include <printf.h>
#include "LinkedListHash.h"

HashTable* hash_table_init(){
    HashTable* hashTable = static_cast<HashTable *>(malloc(sizeof(HashNode)));
    if(hashTable == nullptr)
        return NULL;
    memset(hashTable,0,sizeof(hashTable));
    return hashTable;
}

bool hash_addKey(HashTable* ht,int data){
    HashNode* hashNode;
    if(ht == nullptr)
        return false;
    hashNode = static_cast<HashNode *>(malloc(sizeof(HashNode)));
    if(hashNode == nullptr)
        return false;
    memset(hashNode,0,sizeof(HashNode));
    hashNode->data =data;
    hashNode->next = nullptr;

    if(nullptr == ht->hashKey[data%6]){
        ht->hashKey[data%6] = hashNode;
    }
    HashNode* tmp =  ht->hashKey[data%6];
    while (NULL != tmp->next){
        tmp = tmp->next;
    }
    tmp->next = hashNode;
    return true;
}

bool hash_deleteKey(HashTable* ht,int data){

}

bool hash_modify_key(HashTable* ht,int olddata,int newdata){

}
/**/
HashNode* hash_Lookup(HashTable* ht,int data){
    HashNode* hNode;
    hNode = static_cast<HashNode *>(malloc(sizeof(HashNode)));
    memset(hNode,0,sizeof(HashNode));
    if(nullptr == ht || ht->hashKey[data%6]== nullptr)
        return nullptr;

    hNode = ht->hashKey[data%6]->next;

    while (nullptr != hNode){
        if(data == hNode->data)
            return hNode;
        hNode = hNode->next;
    }
    return NULL;
}