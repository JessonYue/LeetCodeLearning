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
    HashNode *hNode;
    if (nullptr == ht || ht->hashKey[data % 6] == nullptr)
        return false;
    hNode = ht->hashKey[data % 6]->next;
    HashNode *pre = ht->hashKey[data % 6];
    while (nullptr != hNode) {
        if (data == hNode->data)
            break;
        pre = hNode;
        hNode = hNode->next;
    }

    pre->next = hNode->next;

    free(hNode);
    return true;
}

bool hash_modify_key(HashTable *ht, int olddata, int newdata) {
    if (hash_deleteKey(ht, olddata) && hash_addKey(ht, newdata)) {
        return true;
    } else {
        return false;
    }
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
    HashTable *hashTable = hash_table_init();
    hash_addKey(hashTable, 3);
    hash_addKey(hashTable, 3);
    hash_addKey(hashTable, 5);
    hash_addKey(hashTable, 6);
    hash_addKey(hashTable, 2);

    printf("%d\n", hash_deleteKey(hashTable, 6));
    hash_modify_key(hashTable, 3,4);
    printf("%d\n", hash_Lookup(hashTable, 4)->data);
    return 0;
}