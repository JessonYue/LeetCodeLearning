//
// Created by Vashon on 2020/8/6.
//

#include "homework_038.h"

int insertBits_1(int N, int M, int i, int j) {
//    if (j < i || j < 0) return N;
//    // 得到 M 的二进制数的位数
//    unsigned int newM = M, bitCount = 0;
//    while (newM && newM >> 2u) {    // 快速得到数据的位数
//        newM >>= 2u;
//        bitCount += 2;
//    }
//    if (newM) {
//        newM >>= 1u;
//        bitCount++;
//    }
//    newM = M;
//    // 如果 j 与 i 之间的位置不足以容纳 M，则直接返回 N
//    if ((j - i + 1) < bitCount) return N;
//    // 构建一个新的 N
//    unsigned int newN = N, lowBit = 0;
//    newN >>= j;         // 保留 N 的高位
//    newN <<= j;
//    newM <<= (j - bitCount + 1);
//    newN |= newM;       // 合并 M 到新的 N 上
//    for (int k = 0; k < i; lowBit <<= 1, lowBit |= 1, ++k);
//    lowBit &= N;        // 得到 N 的低位
//    newN |= lowBit;
//    return newN;
    // 先构造出除去 M 占用位的 N，即 N 中对应 M 的占用位全为 0，最后 | 一下即可
    unsigned int newN = N;
    newN &= ~(((1u << (j - i + 1)) - 1u) << i);
    newN |= (M << i);
    return newN;
}

void homework_038_0501(void) {
//    int N = 0b10000000111, M = 0b10101, j = 8, i = 4;
    int N = 1143207437, M = 1017033, j = 31, i = 11;
    printf("before --- N : %x M : %x\n", N, M);
    printf("after --- N : %x\n", insertBits_1(N, M, i, j));
}