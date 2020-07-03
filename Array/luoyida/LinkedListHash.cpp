//
// Created by Jesson on 2020/6/25.
//

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "LinkedListHash.h"


HashTable *hash_table_init() {
    HashTable *hashTable = static_cast<HashTable *>(malloc(sizeof(HashTable)));
    if (hashTable == nullptr)
        return NULL;
    //去除脏数据
    memset(hashTable, 0, sizeof(hashTable));
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
    /////////////////
    hashNode->data = data;
    hashNode->next = nullptr;

    if (nullptr == ht->hashKey[data % 7]) {
        ht->hashKey[data % 7] = hashNode;
    } else {//已经有值了才需要循环寻找下一个空的位置
        HashNode *tmp = ht->hashKey[data % 7];
        while (NULL != tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = hashNode;
    }
    return true;
}

int getHashAddress(int key) {
    return key % 7;
}

bool hash_deleteKey(HashTable *ht, int data) {
    HashNode *node = ht->hashKey[getHashAddress(data)];
    HashNode *tmpPre = nullptr;//如果查到的位置不是我要的值，才使用这个参数
    while (node != nullptr) {
        if (node->data == data) {
            break;
        }
        printf("aaa\n");//这里有说明这个数据存在于第二个空位，不是原本应有的位置
        tmpPre = node;//先保存起来，再处理下一个
        node = node->next;
    }
    printf("查找结束\n");
    if (tmpPre != nullptr && node != nullptr) {
        tmpPre->next = node->next;
        return true;
    }
    if (node != nullptr) {
        ht->hashKey[getHashAddress(data)] = node->next;
        return true;
    }
    printf("找不到！%d\n", data);
    return false;
}

/*修改节点*/
bool hash_modify_key(HashTable *ht, int olddata, int newdata) {
    HashNode *node = ht->hashKey[getHashAddress(olddata)];
    HashNode *tmpPre = nullptr;//如果查到的位置不是我要的值，才使用这个参数
    while (node != nullptr) {
        if (node->data == olddata) {
            break;
        }
        printf("aaa\n");//这里有说明这个数据存在于第二个空位，不是原本应有的位置
        tmpPre = node;//先保存起来，再处理下一个
        node = node->next;
    }
    printf("查找结束\n");
    if (tmpPre != nullptr && node != nullptr) {
        node->data = newdata;
        return true;
    }
    if (node != nullptr) {
        ht->hashKey[getHashAddress(olddata)]->data = newdata;
        return true;
    }
    printf("找不到！%d\n", olddata);
    return false;
}

/*查找节点*/
HashNode *hash_Lookup(HashTable *ht, int data) {
    HashNode *hNode;
    hNode = static_cast<HashNode *>(malloc(sizeof(HashNode)));
    memset(hNode, 0, sizeof(HashNode));
    if (nullptr == ht || ht->hashKey[data % 7] == nullptr)
        return nullptr;

    hNode = ht->hashKey[data % 7]->next;

    while (nullptr != hNode) {
        if (data == hNode->data)
            return hNode;
        hNode = hNode->next;
    }
    return NULL;
}


int main(int argc, char *argv[]) {
    printf("start\n");
    int key[] = {7, 8, 30, 21, 18, 9, 14};
    int i;
    HashTable *hashTable = hash_table_init();
    for (i = 0; i < 7; i++) {
        hash_addKey(hashTable, key[i]);
    }
    for (i = 0; i < 7; i++) {
        HashNode *node = hashTable->hashKey[i];
        while (node != nullptr) {
            printf("key:%d\t node:%d\n", key[i], node->data);
            node = node->next;
        }
    }
    printf("---------------------\n");
    hash_modify_key(hashTable, 9, 16);
//    hash_deleteKey(hashTable, 9);
    for (i = 0; i < 7; i++) {
        HashNode *node = hashTable->hashKey[i];
        while (node != nullptr) {
            printf("key:%d\t node:%d\n", key[i], node->data);
            node = node->next;
        }
    }
    return 0;
}
