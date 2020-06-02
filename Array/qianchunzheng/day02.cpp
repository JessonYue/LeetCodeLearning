//
// Created by qianchunzheng on 2020/6/2.
//
#include <iostream>

/**
 * 思路：
 * 有题目描述可知
 * 一层： 1种方法
 * 二层： 2种方法
 * 三层： 3种方法
 * 四层： 5种方法
 * 五层： 8种方法
 * ...
 * n层：（n-1）+(n-2)种方法
 * 即斐波那契数列，那么可以利用递归思想来解决这个问题，即将复杂的问题一步一步
 * 化成简单的问题来解决。
 */
int fibonacciSequence(int n){
    if(n == 1){
        return 1;
    }
    if (n ==2 ){
        return 2;
    }
    return fibonacciSequence(n-1)+fibonacciSequence(n-2);
}


/**
 *
 * 2020.06.2
 * 爬楼梯
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 注意：给定 n 是一个正整数。
 * 示例 1：
 * 输入： 2
 * 输出： 2
 * 解释： 有两种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶
 * 2.  2 阶
 * 示例 2：
 * 输入： 3
 * 输出： 3
 * 解释： 有三种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶 + 1 阶
 * 2.  1 阶 + 2 阶
 * 3.  2 阶 + 1 阶
 */
int main() {
    int n = 7;
    int i = fibonacciSequence(n);
    std::cout << i << std::endl;
    return 0;
}


