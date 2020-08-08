//
// Created by Vashon on 2020/8/7.
//

#ifndef C_HOMEWORK_040_H
#define C_HOMEWORK_040_H

#include "homework_037.h"

/**
    给定一个整数数组，判断是否存在重复元素。
    如果任意一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。

    示例 1:
    输入: [1,2,3,1]
    输出: true

    示例 2:
    输入: [1,2,3,4]
    输出: false

    示例 3:
    输入: [1,1,1,3,3,4,3,2,4,2]
    输出: true
 */

// 方法一：hash 表映射
bool containsDuplicate_1(int *nums, int numsSize);

// 方法二：排序，然后判断前后元素是否相等
bool containsDuplicate_2(int *nums, int numsSize);

// 存在重复元素，LeetCode第217题
void homework_040_217(void);

#endif //C_HOMEWORK_040_H
