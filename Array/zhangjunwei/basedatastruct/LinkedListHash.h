//
// Created by 张俊伟 on 2020/6/26.
//

#ifndef LICODECPP17_LINKEDLISTHASH_H
#define LICODECPP17_LINKEDLISTHASH_H
#define DataType int
#define SIZE 16  //hash table 的容量
typedef struct _hashnode {
    DataType value;
    _hashnode *next;
} HashNode;
typedef struct _hashtable {
    HashNode *hashKey[SIZE];
} LinkedHashTable;

LinkedHashTable *linked_hash_init();

//hash 函数
static int linked_hash_address(DataType data);
 int linked_hash_get_address(HashNode *node);
//查找
HashNode *linked_hash_find(LinkedHashTable *ht, DataType data);

//插入数据
bool linked_hash_addkey(LinkedHashTable *ht, DataType data);

//删除  success return true or failed false
bool linked_hash_delete(LinkedHashTable *ht, DataType data);

bool linked_hash_modify_key(LinkedHashTable *ht, DataType new_data, DataType old_data);
// 遍历 linkedListHash
void linked_hash_view(LinkedHashTable *ht);
#endif //LICODECPP17_LINKEDLISTHASH_H
