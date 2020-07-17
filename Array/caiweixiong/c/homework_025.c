//
// Created by Vashon on 2020/7/9.
//

#include <stdint.h>
#include <stdio.h>

// 方法一：逐位右移统计
int hammingWeight(uint32_t n);
// 方法二：高位消除统计，这种方法某些场景下会大量减少循环的次数
int hammingWeight_(uint32_t n);

// 二进制中1的个数，LeetCode剑指 Offer 15
void homework_025_o15(void) {
    printf("num 1 count : %d", hammingWeight_(15));
}

int hammingWeight(uint32_t n) {
    uint32_t target = n, assist = 0x1, count = 0;
    while (target) {    // 循环次数取决于最高位 1 右边的二进制数的个数
        count += target & assist;
        target >>= assist;
    }
    return count;
}

int hammingWeight_(uint32_t n) {
    uint32_t target = n, count = 0;
    while (target) {    // 循环次数取决于数中二进制位为 1 的个数
        count++;
        target &= target - 1;
    }
    return count;
}
