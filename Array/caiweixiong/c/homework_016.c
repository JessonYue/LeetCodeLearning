//
// Created by Vashon on 2020/6/22.
//

#include <stdio.h>
#include <string.h>

// 数组嵌套，LeetCode第565题
void homework_016_565(void) {
    int arrayNesting_(int *nums, int numsSize);
    int arr[] = {5, 4, 0, 3, 1, 6, 2};
    int max = arrayNesting_(arr, 7);
    printf("max = %d\n", max);
}

// 方法一：暴力法
int arrayNesting(int *nums, int numsSize) { // 0, 2, 1
    if (!nums || numsSize <= 0)
        return 0;
    int temp[numsSize];
    int max = 1, count = 0, index = 0;
    for (int i = 0; i < numsSize;) {
        int exist = 0;
        for (int j = 0; j < count; ++j) {
            if (temp[j] == index) { // 存在当前查询的索引，结束循环
                exist = 1;
                break;
            }
        }
        if (!exist) {   // 不存在当前索引，将索引加入数组并获取下一个索引
            temp[count++] = index;
            index = nums[index];
        } else {        // 存在当前索引，获取长度，重置信息
            max = max > count ? max : count;
            if (max == numsSize)    // 最大的组合不可能超过数组的长度
                break;
            count = 0;
            index = ++i;
        }
    }
    return max;
}

// 方法二：标记法
int arrayNesting_(int *nums, int numsSize) { // 5, 4, 0, 3, 1, 6, 2
    if (!nums || numsSize <= 0)
        return 0;
    int visit[numsSize];
    int res = 0;
    for (int j = 0; j < numsSize; ++j) {
        if (visit[j] != 3) {        // 未访问过的位置
            int start = nums[j], count = 0;
            do {
                start = nums[start];
                count++;
                visit[start] = 3;   // 将对应位置置为已经访问
            } while (start != nums[j]);
            res = res > count ? res : count;
        }
    }
    return res;
}