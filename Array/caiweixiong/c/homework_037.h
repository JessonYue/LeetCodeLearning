//
// Created by Vashon on 2020/8/5.
//

#ifndef C_HOMEWORK_037_H
#define C_HOMEWORK_037_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

/**
    给定两个数组，编写一个函数来计算它们的交集。
    示例 1：
    输入：nums1 = [1,2,2,1], nums2 = [2,2]
    输出：[2]

    示例 2：
    输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    输出：[9,4]
     
    说明：
    输出结果中的每个元素一定是唯一的。
    我们可以不考虑输出结果的顺序。
 */
 // 方法一：暴力法
int *intersection_1(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize);

// 方法二：hash 法，空间换时间
int *intersection_2(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize);

// 方法三：排序 + 归并
int *intersection_3(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize);

// 排序
int compare(const void *nums1, const void *nums2);

// 两个数组的交集，LeetCode第349题
void homework_037_349(void);

#endif //C_HOMEWORK_037_H
