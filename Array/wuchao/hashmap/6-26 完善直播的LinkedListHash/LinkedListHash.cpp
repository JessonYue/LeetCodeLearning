//
// Created by Jesson on 2020/6/25.
//

#include <cstdlib>
#include <cstring>
#include <printf.h>
#include "LinkedListHash.h"
HashTable* hash_table_init();
bool hash_addKey(HashTable* ht,int data);
void print_hash_table(HashTable* hashTable);
bool hash_deleteKey(HashTable* ht,int data);
bool hash_modify_key(HashTable* ht,int olddata,int newdata);
HashNode* hash_Lookup(HashTable* ht,int data);
int main(){
    HashTable * hashTable = hash_table_init();
    hash_addKey(hashTable,65);
    hash_addKey(hashTable,15);
    hash_addKey(hashTable,4);
    hash_addKey(hashTable,687);
    print_hash_table(hashTable);
    hash_deleteKey(hashTable,15);
    print_hash_table(hashTable);
    hash_addKey(hashTable,5);
    hash_addKey(hashTable,6);
    print_hash_table(hashTable);
    hash_modify_key(hashTable,687,9);
    print_hash_table(hashTable);
    HashNode * node = hash_Lookup(hashTable,9);
    hash_addKey(hashTable,87);
    print_hash_table(hashTable);
    if(node== nullptr){
        printf("not found");
    } else {
        printf("found %d",node->data);
    }
}

HashTable* hash_table_init(){
    HashTable* hashTable = static_cast<HashTable *>(malloc(sizeof(HashTable)));
    if(hashTable == nullptr)
        return nullptr;
    memset(hashTable,0,sizeof(HashTable));
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
        //建立一个哨兵节点，放在数组这个地方
        HashNode* head;
        head = static_cast<HashNode *>(malloc(sizeof(HashNode)));
        memset(head,0,sizeof(HashNode));
        head->data = -1;
        head->next = nullptr;
        ht->hashKey[data%6] = head;
    }
    HashNode* tmp =  ht->hashKey[data%6];
    while (nullptr != tmp->next){
        tmp = tmp->next;
    }
    tmp->next = hashNode;
    return true;
}

bool hash_deleteKey(HashTable* ht,int data){
    if(nullptr == ht->hashKey[data%6]){
        return false;
    }
    HashNode* temp = ht->hashKey[data%6];
    while(temp->next!= nullptr){
        if(temp->next->data == data){
            break;
        }
        temp = temp->next;
    }
    if(temp->next== nullptr){
        return false;
    }
    HashNode * next = temp->next;
    temp->next = next->next;
    next->next = nullptr;
    free(next);
    return true;
}

bool hash_modify_key(HashTable* ht,int olddata,int newdata){
    //旧值下标处没有元素，返回false
    if(nullptr == ht->hashKey[olddata%6]){
        return false;
    }
    HashNode * temp = ht->hashKey[olddata%6];
    while(temp->next!= nullptr){
        if(temp->next->data == olddata){
            break;
        }
        temp = temp->next;
    }
    if(temp->next== nullptr){
        return false;
    }
    //两个值hash相同，则赋值为newData
    if(olddata%6==newdata%6){
        temp->next->data = newdata;
        return true;
    } else {//不同，则需要先删除oldData，再插入newData
        HashNode *next = temp->next;
        temp->next = next->next;
        next->next = nullptr;
        free(next);
        return hash_addKey(ht,newdata);
    }
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
    return nullptr;
}

void print_hash_table(HashTable* hashTable){
    int i =0;
    while(i<6){
        HashNode * hashNode = hashTable->hashKey[i];
        if(hashNode!= nullptr){
            while(hashNode->next!= nullptr){
                printf("%d,",hashNode->next->data);
                hashNode = hashNode->next;
            }
            printf("\n");
        }
        i++;
    }
    printf("----\n");
}