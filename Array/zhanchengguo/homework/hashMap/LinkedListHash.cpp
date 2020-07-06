//
// Created by Jesson on 2020/6/25.
//

#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include "LinkedListHash.h"

HashTable *hash_table_init() {
    HashTable *hashTable = static_cast<HashTable *>(malloc(sizeof(HashTable)));
    if (hashTable == nullptr)
        return NULL;
    memset(hashTable, 0, sizeof(HashTable));
    return hashTable;
}

bool hash_addKey(HashTable *ht, int data) {
    HashNode *hashNode;
    if (ht == nullptr)
        return false;
    hashNode = static_cast<HashNode *>(malloc(sizeof(HashNode)));
    if (hashNode == nullptr)
        return false;
    memset(hashNode, 0, sizeof(HashNode));
    hashNode->data = data;
    hashNode->next = nullptr;

    if (nullptr == ht->hashKey[data % 6]) {
        HashNode *head = static_cast<HashNode *>(malloc(sizeof(HashNode)));
        memset(head, 0, sizeof(HashNode));
        ht->hashKey[data % 6] = head;
    }
    HashNode *tmp = ht->hashKey[data % 6];
    while (NULL != tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = hashNode;
    return true;
}

bool hash_deleteKey(HashTable *ht, int data) {
    // 判空处理
    if (ht == nullptr) {
        return false;
    }
    if (ht->hashKey[data % 6] == nullptr) {
        return false;
    }
    //根据hash函数获取HashTab的中的链表头
    HashNode *hashNode = ht->hashKey[data % 6];
    HashNode *preTemp = nullptr;
    //判断链表的值是否符合删除的值
    while (hashNode != nullptr) {
        if (hashNode->data == data) {
            break;
        }
        preTemp = hashNode;
        hashNode = hashNode->next;
    }
    //表头符合数据
    if (preTemp == nullptr) {
        ht->hashKey[data % 6] = hashNode->next;
        return true;
    }
    if (hashNode != nullptr && preTemp != nullptr) {
        preTemp->next = hashNode->next;
        return true;
    }
    return false;
}

bool hash_modify_key(HashTable *ht, int olddata, int newdata) {
    return hash_deleteKey(ht, olddata) && hash_addKey(ht, newdata);
}

/**/
HashNode *hash_Lookup(HashTable *ht, int data) {
    HashNode *hNode;
//    hNode = static_cast<HashNode *>(malloc(sizeof(HashNode)));
//    memset(hNode,0,sizeof(HashNode));
    if (nullptr == ht || ht->hashKey[data % 6] == nullptr)
        return nullptr;

    hNode = ht->hashKey[data % 6]->next;

    while (nullptr != hNode) {
        if (data == hNode->data)
            return hNode;
        hNode = hNode->next;
    }
    return NULL;
}

int main() {
    printf("----------init-----------\n");
    HashTable *hashTable = hash_table_init();
    printf("----------add-----------\n");
    hash_addKey(hashTable, 3);
    hash_addKey(hashTable, 3);
    hash_addKey(hashTable, 5);
    hash_addKey(hashTable, 6);
    hash_addKey(hashTable, 2);

    printf("----------delete-----------\n");
    printf("%d\n", hash_deleteKey(hashTable, 6));

    printf("----------modify-----------\n");
    hash_modify_key(hashTable, 3, 4);
    printf("%d\n", hash_Lookup(hashTable, 4)->data);
    return 0;
}
