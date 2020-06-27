#include <iostream>
#include "basedatastruct/hash.cpp"

void hash_test(){
    int key[]={7,8,30,11,18,9,14};
    int i;
    hashtable_init();

    for(i = 0; i<7; i++)
    {
        hashtable_insert(key[i]);
    }

    for(i = 0; i<7; i++)
    {
        int address;
        address = find(key[i]);
        printf("key:%d\t address:%d\n", key[i],address);
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    hash_test();
    return 0;
}
