#include <iostream>
#include "basedatastruct/hash.cpp"
#include "basedatastruct/LinkedListHash.h"

void hash_test() {
    int key[] = {7, 8, 30, 11, 18, 9, 14};
    int i;
    hashtable_init();

    for (i = 0; i < 7; i++) {
        hashtable_insert(key[i]);
    }

    for (i = 0; i < 7; i++) {
        int address;
        address = find(key[i]);
        printf("key:%d\t address:%d\n", key[i], address);
    }
}

void linkedhash_test() {
    int key[] = {7, 8, 30, 11, 18, 9, 14};
    int i;
    LinkedHashTable *ht = linked_hash_init();

    for (i = 0; i < 7; i++) {
        linked_hash_addkey(ht, key[i]);
    }

    for (i = 0; i < 7; i++) {
        HashNode *node;
        node = linked_hash_find(ht, key[i]);
        int addr = linked_hash_get_address(node);
        printf("key:%d\t node:%d\n", key[i], addr);
    }
    bool res = linked_hash_delete(ht, 7);
    printf("删除操作:%d\t node:%d\n",7, res);
    printf("删除操作:%d\t node:%d\n",6, linked_hash_delete(ht, 6));
    printf("删除操作:%d\t node:%d\n",14, linked_hash_delete(ht, 17));
    linked_hash_view(ht);

}

int main() {
    std::cout << "Hello, World!" << std::endl;
//    hash_test();
    linkedhash_test();
    return 0;
}
