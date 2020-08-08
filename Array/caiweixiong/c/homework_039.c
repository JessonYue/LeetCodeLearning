//
// Created by Vashon on 2020/8/7.
//

#include "homework_039.h"

bool hasAlternatingBits(int n) {
    // 巧用异或操作，只要 n 满足 1010...，那么，异或结果必定是 00..11111，所以 +1 后，必定进位，所以若 n 满足条件 temp & temp + 1 必为 0
    unsigned int temp = n ^ (n >> 1);
    return (temp & (temp + 1)) == 0;
}

void homework_039_693(void) {
    int n = 0b101010;
    printf("input num is : %x", n);
    if (hasAlternatingBits(n))
        printf("the num query result is true");
    else
        printf("the num query result is false");
}