//
// Created by Vashon on 2020/6/28.
//

#include <stdio.h>

// 大小为 K 且平均值大于等于阈值的子数组数目，LeetCode第1343题
void homework_021_1343(void) {
    int numOfSubarrays_(int *arr, int arrSize, int k, int threshold);
    int arr[] = {2, 2, 2, 2, 5, 5, 5, 8}, k = 3, threshold = 4;
    printf("accord arr num is : %d\n", numOfSubarrays_(arr, 8, k, threshold));
}

// 方法一：暴力法，但是LeetCode不通过，超出时间限制...
int numOfSubarrays(int *arr, int arrSize, int k, int threshold) {
    if (!arr || arrSize <= 0 || arrSize < k)
        return 0;
    int count = arrSize - k + 1;    // 得到满足 k 个元素的所有的子数组量
    int accord = 0, offset = 0, sum = 0, allSum = threshold * k;
    while (count--) {
        for (int i = offset; i < k + offset; ++i) {
            sum += arr[i];          // 得到区间内的累加和
            if (sum >= allSum) {    // 当部分累加和比需要的总额大时，不需要继续循环
                accord++;           // 满足条件
                break;
            }
        }
        sum = 0;
        offset++;
    }
    return accord;
}

// 方法二：移动指针法
int numOfSubarrays_(int *arr, int arrSize, int k, int threshold) {  // [11,13,17,23,29,31,7,5,2,3]，3，5
    if (!arr || arrSize <= 0 || arrSize < k)
        return 0;
    int count = arrSize - k;    // 得到满足 k 个元素的所有的子数组量
    int accord = 0, sum = 0, allSum = threshold * k, left = 0, right = k;
    for (int i = 0; i < k; ++i) {
        sum += arr[i];          // 得到区间内的累加和
    }
    if (sum >= allSum)
        accord++;
    while (count--) {
        sum = (sum - arr[left++] + arr[right++]);    // 将组内的第一个元素与组外第一个元素替换，并将指针索引增加
        if (sum >= allSum)
            accord++;
    }
    return accord;
}