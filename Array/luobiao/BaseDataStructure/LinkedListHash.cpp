//
// Created by Jesson on 2020/6/25.
//

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
#include "LinkedListHash.h"
using namespace std;

HashTable* hash_table_init(){
    HashTable* hashTable = static_cast<HashTable *>(malloc(sizeof(HashTable)));
    if(hashTable == nullptr)
        return NULL;
    memset(hashTable,0,sizeof(hashTable));

    //分配内存完成后需要初始化一下，不然会有异常数据
    for (int i = 0; i <Len ; ++i) {
        *(hashTable->hashKey + i) = NULL;
    }
    return hashTable;
}

/*Hash函数*/
int getHashAddress(int key)
{
    return key % Len;
}

bool hash_addKey(HashTable* ht,int data){
    HashNode* hashNode;
    if(ht == NULL)
        return false;
    hashNode = static_cast<HashNode *>(malloc(sizeof(HashNode)));
    if(hashNode == NULL)
        return false;
    memset(hashNode,0,sizeof(HashNode));
    hashNode->data =data;
    hashNode->next = NULL;

    if(nullptr == ht->hashKey[getHashAddress(data)]){
        ht->hashKey[getHashAddress(data)] = hashNode;
    } else {
        HashNode* tmp =  ht->hashKey[getHashAddress(data)];
        HashNode* tmpPre = NULL;
        while (tmp != NULL){
            tmpPre = tmp;
            tmp = tmp->next;
        }

        tmpPre->next = hashNode;
    }

    return true;
}

/**
 * 删除节点
 * @param ht
 * @param data
 * @return
 */
bool hash_deleteKey(HashTable* ht,int data){
    if (ht == NULL) {
        return false;
    }

    HashNode* tmp = ht->hashKey[getHashAddress(data)];
    HashNode* tmpPre = nullptr;
    while (tmp != nullptr) {
        if (tmp->data == data) {
            break;
        }
        tmpPre = tmp;
        tmp = tmp->next;
    }

    if(tmpPre != nullptr) {
        tmpPre->next = tmp->next;
        free(tmp);
        return true;
    } else if(tmp != nullptr){
        ht->hashKey[getHashAddress(data)] = tmp->next;
        free(tmp);
        return true;
    } else {
        printf("hash node is NULL.");
    }

    return false;
}

/**
 * 切换两个节点
 * @param ht
 * @param olddata
 * @param newdata
 * @return
 */
bool hash_modify_key(HashTable* ht,int olddata,int newdata){
    if (ht == NULL) {
        return false;
    }

    HashNode* tmpStartOld = ht->hashKey[getHashAddress(olddata)];
    HashNode* tmpStartOldPre = nullptr;


    HashNode* tmpStartNew = ht->hashKey[getHashAddress(newdata)];
    HashNode* tmpStartNewPre = nullptr;

    while (tmpStartOld != NULL) {
        if(tmpStartOld->data == olddata) {
            break;
        }
        tmpStartOldPre = tmpStartOld;
        tmpStartOld = tmpStartOld->next;
    }


    while (tmpStartNew != NULL) {
        if(tmpStartNew->data == newdata) {
            break;
        }

        tmpStartNewPre = tmpStartNew;
        tmpStartNew = tmpStartNew->next;
    }

    /**
     * 替换数值方式
     */
//    if (tmpStartNew != nullptr &&  tmpStartOld != nullptr) {
//        int tmpData = tmpStartNew->data;
//        tmpStartNew->data = tmpStartOld->data;
//        tmpStartOld->data = tmpData;
//    } else {
//        cout<<"====No found olddata or newdata value========="<< endl;
//    }


    /**
     * 节点切换方式
     */
    if(tmpStartOldPre != nullptr) {
        tmpStartOldPre->next = tmpStartNew;
    } else {
        ht->hashKey[getHashAddress(olddata)] = tmpStartNew;
    }

    if(tmpStartNewPre != nullptr) {
        tmpStartNewPre->next = tmpStartOld;
    } else {
        ht->hashKey[getHashAddress(newdata)] = tmpStartOld;
    }

    HashNode * tmp = tmpStartNew->next;
    tmpStartNew->next = tmpStartOld->next;
    tmpStartOld->next = tmp;


    return true;
}
/**/
HashNode* hash_Lookup(HashTable* ht,int data){
    HashNode* hNode;
    hNode = static_cast<HashNode *>(malloc(sizeof(HashNode)));
    memset(hNode,0,sizeof(HashNode));
    if(NULL == ht || ht->hashKey[getHashAddress(data)] == NULL)
        return NULL;

    hNode = ht->hashKey[getHashAddress(data)]->next;

    while (nullptr != hNode){
        if(data == hNode->data)
            return hNode;
        hNode = hNode->next;
    }
    return NULL;
}

void printf_hashList(HashTable* ht) {
    if (ht == NULL) {
        return;
    }

    for(int i = 0; i<Len; i++)
    {
        HashNode* node = ht->hashKey[i];

        while (node != NULL) {
            cout<<"key:"<< i << "  hash value:"<< node->data << endl;
            node = node->next;
        }

    }
    hash_Lookup
}


int main()
{
    int key[]={7,8,30,11,18,9,14,58,37,19,90,100,112,134,156};
    int i;
    HashTable* ht = hash_table_init();

    for(i = 0; i<15; i++)
    {
        hash_addKey(ht, key[i]);
    }

    cout<<"All LikeListHash Data"<< endl;
    printf_hashList(ht);

    hash_modify_key(ht, 30, 9);

    cout<<"Switch between 30 and 9 Node"<< endl;
    printf_hashList(ht);

    hash_deleteKey(ht, 14);

    cout<<"Remove 14 nodes"<< endl;
    printf_hashList(ht);

    return 0;
}






































