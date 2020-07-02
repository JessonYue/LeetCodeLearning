//
// Created by 张俊伟 on 2020/6/26.
//

#include "LinkedListHash.h"
#include <cstdlib>
#include <string>

LinkedHashTable *linked_hash_init() {
    LinkedHashTable *ht = static_cast<LinkedHashTable *>(malloc(sizeof(LinkedHashTable)));
    if (ht == nullptr)
        return nullptr;
    memset(ht, 0, sizeof(LinkedHashTable));
    return ht;
}

//hash 函数
static int linked_hash_address(DataType data) {
    return data * 3 % 7;
}
int linked_hash_get_address(HashNode *node){
    if (node== nullptr || node->value == -1)return -1;
   return linked_hash_address(node->value);
}

HashNode *linked_hash_find(LinkedHashTable *ht, DataType data) {
    int addr = linked_hash_address(data);
    HashNode *node = ht->hashKey[addr];
    if (node == nullptr)return nullptr;
    node = node->next;
    while (node != nullptr && node->value != data) {
        node = node->next;
    }
    return node;
}

//插入数据
bool linked_hash_addkey(LinkedHashTable *ht, DataType data) {
    int addr = linked_hash_address(data);
    HashNode *head_node = ht->hashKey[addr];//头结点不用于存储数据
    if (head_node == nullptr) {
        head_node = static_cast<HashNode *>(malloc(sizeof(HashNode)));
        if (head_node == nullptr)return false;
        head_node->next = nullptr;
        head_node->value = -1;
    }
    HashNode *tmp = static_cast<HashNode *>(malloc(sizeof(HashNode)));
    if (tmp == nullptr)return false;
    //新创建的结点插到头结点的后面
    tmp->value = data;
    tmp->next = head_node->next;
    head_node->next = tmp;
    ht->hashKey[addr] = head_node;
    return true;
}

//删除  success return true or failed false
bool linked_hash_delete(LinkedHashTable *ht, DataType data) {
    int addr = linked_hash_address(data);
    HashNode *head_node = ht->hashKey[addr];//头结点不用于存储数据
    if (head_node == nullptr)return false;
    HashNode **tmp = &head_node->next;
    while (*tmp != nullptr && (*tmp)->value != data) {
        tmp = &(*tmp)->next;
    }
    //要删除的数据结点不存在
    if (*tmp == nullptr)return false;
    //*tmp为要删除的结点
    *tmp = (*tmp)->next;

    return true;

}

bool linked_hash_modify_key(LinkedHashTable *ht, DataType new_data, DataType old_data) {
    HashNode *destNode = linked_hash_find(ht, old_data);
    if (destNode == nullptr)return false;
    destNode->value = new_data;
    return true;
}

//打印链表
void node_view(HashNode *node){
    if (node== nullptr || node->next== nullptr)return;
    node = node->next;
    int addr = linked_hash_get_address(node);
    while (node!= nullptr){
        printf("key[%d] %d\n",addr,node->value);
        node = node->next;
    }
}
// 遍历 linkedListHash
void linked_hash_view(LinkedHashTable *ht){
    for (int i = 0; i <SIZE; ++i) {
        node_view(ht->hashKey[i]);
    }
}