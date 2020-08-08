//
// Created by Vashon on 2020/8/7.
//

#include "homework_040.h"

bool containsDuplicate_1(int *nums, int numsSize) {
    // 这种方法虽然很便捷并且很快，但是浪费大量内存
    int temp1[1u << 10u] = {0}, temp2[1u << 10u] = {0}, *n = nums;
    for (int i = 0; i < numsSize; n++, ++i) {
        if(*n >= 0) {
            if (temp1[*n]) return true;
            else temp1[*n]++;
        } else {
            if (temp2[-*n]) return true;
            else temp2[-*n]++;
        }
    }
    return false;
}

bool containsDuplicate_2(int *nums, int numsSize) {
    if (!nums || numsSize <= 1) return false;
    int *n = nums, prior = 0, next = 1;
    qsort(n, numsSize, sizeof(int), compare);
    while (next < numsSize) {
        if (n[prior++] == n[next++])
            return true;
    }
    return false;
}

void homework_040_217(void) {
    int a[4] = {1, 2, 3, 4};
    if (containsDuplicate_2(a, 4))
        printf("the array contains duplicate result is : true");
    else
        printf("the array contains duplicate result is : false");
}