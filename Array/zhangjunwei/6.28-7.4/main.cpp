#include <iostream>
#include "basedatastruct/hash.cpp"
#include "basedatastruct/LinkedListHash.h"
#include "july/matrixOperations.cpp"
#include "july/LCS.cpp"

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
    printf("删除操作:%d\t node:%d\n", 7, res);
    printf("删除操作:%d\t node:%d\n", 6, linked_hash_delete(ht, 6));
    printf("删除操作:%d\t node:%d\n", 14, linked_hash_delete(ht, 17));
    linked_hash_view(ht);

}

void testMatrix() {
    int arr1[] = {
            1, 0, 2,
            -1, 3, 1
    };
    int arr2[] = {
            3, 1,
            2, 1,
            1, 0
    };
    Matrix *m1, *m2;
    matrix_create_by(&m1, arr1, 2, 3);
    matrix_create_by(&m2, arr2, 3, 2);
    matrix_view(m1);
    matrix_view(m2);
    Matrix *m3 = matrix_multiply(*m1, *m2);
    std::cout << "matrix_multiply" << std::endl;
    matrix_view(m3);
    Matrix *m4 = matrix_multiply_num(*m1, 2);
    std::cout << "matrix_multiply_num" << std::endl;
    matrix_view(m4);
    Matrix *m5 = matrix_plus(*m2, *m2);
    std::cout << "matrix_plus" << std::endl;
    matrix_view(m5);

    matrix_free(m1);
    matrix_free(m2);
    matrix_free(m3);
    matrix_free(m4);
    matrix_free(m5);
}

void testLCS() {
    //"",""
    const char *s1 = "bdcaba";
    const char *s2 = "abcbdab";
    const char *s3 = get_lcs(s1, s2);
    std::cout << s3 << std::endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
//    hash_test();
//    linkedhash_test();

//    testMatrix();
    testLCS();
    return 0;
}
