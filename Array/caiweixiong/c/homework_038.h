//
// Created by Vashon on 2020/8/6.
//

#ifndef C_HOMEWORK_038_H
#define C_HOMEWORK_038_H

#include <stdio.h>

/**
    插入。给定两个32位的整数 N 与 M，以及表示比特位置的 i 与 j。编写一种方法，将 M 插入 N，使得 M 从 N 的第 j 位开始，到第 i 位结束。假定从 j 位到 i 位足以容纳 M，
         也即若 M = 10011，那么 j 和 i 之间至少可容纳 5 个位。例如，不可能出现 j = 3 和 i = 2 的情况，因为第 3 位和第 2 位之间放不下 M。

    示例1:
    输入：N = 10000000000, M = 10011, i = 2, j = 6
    输出：N = 10001001100

    示例2:
    输入：N = 0, M = 11111, i = 0, j = 4
    输出：N = 11111
 */

int insertBits_1(int N, int M, int i, int j);

// 插入，LeetCode面试题05.01
void homework_038_0501(void);

#endif //C_HOMEWORK_038_H
