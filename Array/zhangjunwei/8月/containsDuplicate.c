
#include <stdbool.h>
/**
 * 给定一个整数数组，判断是否存在重复元素。

如果任意一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。
*/

int find_hash(int n, int * hash, int size)
{
    int location = (n + size / 2) % size;
    if (location < 0) {
        location = -location;
    }

    while (hash[location] != n && hash[location] != -234567) {
        location++;
        if (location >= size) {
            location = 0;
        }
    }

    if (hash[location] == n) {
        return 1;
    }
    else {
        return 0;
    }
}

void insert_hash(int n, int * hash, int size)
{
    int location = (n + size / 2) % size;
    if (location < 0) {
        location = -location;
    }

    while (hash[location] != -234567) {
        location++;
        if (location >= size) {
            location = 0;
        }
    }

    hash[location] = n;

    return;
}

void init_hash(int * hash, int size)
{
    int i;

    for (i = 0; i < size; i++) {
        hash[i] = -234567;
    }

    return;
}

bool containsDuplicate(int* nums, int numsSize){

    if (numsSize == 0) {
        return false;
    }

    int hash_size = 5 * numsSize;

    int hash[hash_size];
    int i;

    init_hash(hash, hash_size);

    for (i = 0; i < numsSize; i++) {
        if (find_hash(nums[i], hash, hash_size)) {
            return true;
        }
        else {
            insert_hash(nums[i], hash, hash_size);
        }
    }
    return false;
}
