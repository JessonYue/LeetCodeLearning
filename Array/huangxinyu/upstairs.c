//
// Created by hasee on 2020/6/2.
//
/**
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * f(1) = 1,f(2) = 2,f(3) = 3,f(5) = 5
 * f(n) = f(n-1)+f(n-2)
 *
 */
#include "alo.h"

int climbStairs(const int n) {
    if (n == 1) {
        return 1;
    }
    int pp = 1;//pre pre
    int p = 2;//pre
    for (int i = 3; i <= n; i++) {
        int cur = p + pp;
        pp = p;
        p = cur;
    }
    return p;
}
