//
// Created by qiguang.zhu on 2020/7/7.
//
#include <stdio.h>

/**
 * 任意给定一个32位无符号整数n，求n的二进制表示中1的个数，比如n = 5（0101）时，返回2，n = 15（1111）时，返回4
 * @param n
 * @return
 */
int one_size(unsigned int n);

int one_size(unsigned int n) {
    int count = 0;
    while (n > 0) {
        if ((n & 1) == 1) {
            count++;
        }
        n >>= 1;
    }
    return count;
}

int main() {
    printf("5 size of 1 is %d\n", one_size(5));//5->0101
    printf("23 size of 1 is %d", one_size(23));//23->10111
    return 0;
}
