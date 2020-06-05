//
//  homework_001.c
//  BaseBuild
//
//  Created by mac on 2020/6/1.
//  Copyright © 2020 mingxi. All rights reserved.
//

#include <stdio.h>

// 两数之和II，注意，它们是有序表，LeetCode第1题
void homework_001_001(void) {
    int i, index1 = 0, index2 = 0;
    int array[5] = {3, 8, 9, 21, 30};
    printf("输入目标数字：");
    scanf("%d", &i);
    int twoSum(int array[], int length, int target, int *index1, int *index2);
    if (twoSum(array, 5, i, &index1, &index2))
        printf("目标的索引为：[%d, %d]\n", index1, index2);
    else
        printf("没有发现合适的索引\n");
}

int twoSum(int array[], int length, int target, int *index1, int *index2) {
    int i, j;
    for (i = 0; i < length; i++) {
        // 如果一个数就比目标数大，那后面就不需要检查了，因为是有序数组
        if (array[i] > target)
            return 0;
        for (j = 0; j < length; j++) {
            // 不能是同一个数
            if (i == j)
                continue;
            // 如果其中一个数比目标大或者两数之和比目标大，直接进行下一轮循环
            if (array[j] > target || array[i] + array[j] > target)
                break;
            if (array[i++] + array[j++] == target) {
                // 获取对应的索引，值为下标 + 1
                *index1 = i > j ? j : i;
                *index2 = i > j ? i : j;
                return 1;
            }
        }
    }
    return 0;
}

