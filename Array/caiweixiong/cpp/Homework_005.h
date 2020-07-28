//
// Created by Vashon on 2020/7/27.
//

/**
给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。

初始化 A 和 B 的元素数量分别为 m 和 n。

示例:

输入:
A = [1,2,3,0,0,0], m = 3
B = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]
说明:

A.length == n + m
 */

#ifndef HOMEWORK_HOMEWORK_005_H
#define HOMEWORK_HOMEWORK_005_H

#include <vector>

using namespace std;

class Homework_005 {
private:
    void merge(vector<int> &A, int m, vector<int> &B, int n);

public:
    // 合并排序数组，LeetCode面试题10.01
    void homework_005_1001();
};


#endif //HOMEWORK_HOMEWORK_005_H
