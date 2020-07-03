//
// Created by LCX on 2020/7/3.
//


#include <malloc.h>
#include <memory.h>
#include "LinkedListHash.h"

HashTable* init_HashTable(){
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    if(hashTable == NULL)
        return NULL;
    memset(hashTable,0, sizeof(HashTable));
    return hashTable;
}
//插入
bool hash_addKey(HashTable* hashTable,DataType data)
{
    if(hashTable == NULL)
        return false;
    HashNode *hashNode = (HashNode*)malloc(sizeof(HashNode));
    if(hashNode == NULL)
        return false;
    memset(hashNode,0, sizeof(HashNode));
    hashNode->data = data;
    hashNode->next = NULL;
    if(hashTable->hashKey[data%Len] == NULL) //空才可以插入
    {
        HashNode *head = (HashNode*)malloc(sizeof(HashNode));
        if (head == NULL)
            return NULL;
        memset(head,0, sizeof(HashNode));
        hashTable->hashKey[data%Len] = head;
    }
    HashNode *tmp = hashTable->hashKey[data%Len];
    while (tmp->next!=NULL){
        tmp = tmp->next;
    }
    tmp->next = hashNode;
    return true;
}
//删除
bool hash_deleteKey(HashTable* hashTable,DataType data)
{
    if(hash_lookup(hashTable,data) != NULL)
    {
        HashNode *cur = hash_lookup(hashTable,data);
        printf("delete:%d\n",cur->data);
        HashNode *hashNode= hashTable->hashKey[data%Len]->next;
        HashNode *pre= hashTable->hashKey[data%Len];
        while (hashNode != NULL)
        {
            if(hashNode->data == data)
                break;
            pre = hashNode;
            hashNode = hashNode->next;
        }
        pre->next = hashNode->next;
        free(hashNode);
        return true;
    } else
    {
        //printf("删除失败,没有找到该元素");
        printf("delete faile\n");
        return false;
    }

}
//修改
bool hash_modifyKey(HashTable* hashTable,DataType oldData,DataType newData)
{
    if(hash_lookup(hashTable,oldData)!=NULL)
    {
        bool deldeteNode = hash_deleteKey(hashTable,oldData);
        if (deldeteNode)
        {
            bool addNode = hash_addKey(hashTable,newData);
            if (addNode)
                return true;
            else
                return false;
        }
        else
        {
            return false;
        }
    }
    else
    {
        printf("modify faile, not find oldData\n");
        return false;
    }
}

//查找
HashNode* hash_lookup(HashTable *hashTable,DataType data)
{
    if(hashTable == NULL)
        return NULL;
    HashNode *hashNode = (HashNode*)malloc(sizeof(HashNode));
    if(hashNode == NULL || hashTable->hashKey[data%Len] == NULL)
        return NULL;
    memset(hashNode,0, sizeof(HashNode));
    hashNode = hashTable->hashKey[data%Len]->next;
    while (hashNode != NULL)
    {
        if(hashNode->data == data)
            return hashNode;
        hashNode = hashNode->next;
    }
    printf("not find somthing\n");
    return NULL;
}

int main()
{
    printf("%d\n",13%6);
    printf("%d\n",1%6);
    printf("-------\n");
    HashTable * hashTable = init_HashTable();
    hash_addKey(hashTable,1);
    hash_addKey(hashTable,2);
    hash_addKey(hashTable,3);
    hash_addKey(hashTable,13);
    hash_addKey(hashTable,4);

    printf("%d\n",hash_lookup(hashTable,13)->data);
    hash_deleteKey(hashTable,1);
    hash_deleteKey(hashTable,13);
    //hash_deleteKey(hashTable,1);
    hash_modifyKey(hashTable,2,5);
    printf("%d\n",hash_lookup(hashTable,2)->data);
    printf("%d\n",hash_lookup(hashTable,5)->data);
    return 0;
}
