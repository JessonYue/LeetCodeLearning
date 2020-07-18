//
// Created by Vashon on 2020/7/15.
//

#include <stdlib.h>
#include <stdio.h>

/*
给你两个数组，arr1 和 arr2，

arr2 中的元素各不相同
arr2 中的每个元素都出现在 arr1 中
对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾

输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
输出：[2,2,2,1,4,3,3,9,6,7,19]
*/

int *relativeSortArray(int *arr1, int arr1Size, int *arr2, int arr2Size, int *returnSize);

// 数组的相对排序，LeetCode第1122题
void homework_030_1122(void) {
    int arr1[11] = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19}, arr2[6] = {2, 1, 4, 3, 9, 6};
    int returnSize = 0, *returnArr = NULL;
    returnArr = relativeSortArray(arr1, 11, arr2, 6, &returnSize);

    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", returnArr[i]);
    }
    printf("\n");
    free(returnArr);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *relativeSortArray(int *arr1, int arr1Size, int *arr2, int arr2Size, int *returnSize) {
    if (!arr1 || !arr2 || (arr1Size < arr2Size)) {
        *returnSize = 0;
        return NULL;
    }
    // 1.将数组1升序排序
    // 2.迭代数组2，按照数组2的元素顺序从数组1中取出，并保存到新数组，将取出的元素位置为无效数
    // 3.最后迭代数组1，将不是无效数的元素一次插入到新数组尾部
    int temp1[arr1Size], *temp2 = arr2, voidNum = 1 << (8 * sizeof(int) - 2), index = 0;
    int *returnArr = malloc(arr1Size * sizeof(int));
    *returnSize = arr1Size;
    // 将数组1复制到一个临时数组
    for (int i = 0; i < arr1Size; ++i)
        temp1[i] = arr1[i];
    // 1.排序
    for (int i = 0, j = i; i < arr1Size - 1; j = ++i) {
        int ai = temp1[i + 1];
        while (ai < temp1[j]) {
            temp1[j + 1] = temp1[j];
            if (j-- == 0) {
                break;
            }
        }
        temp1[j + 1] = ai;
    }
    // 2.
    for (int i = 0; i < arr2Size; ++i) {
        for (int j = 0; j < arr1Size; ++j) {
            if (temp1[j] & voidNum) // 当数据为无效值时，跳过本次循环
                continue;
            if (temp1[j] == temp2[i]) {
                returnArr[index++] = temp1[j];
                temp1[j] = voidNum;
            }
        }
    }
    // 3.
    for (int k = 0; k < arr1Size; ++k) {
        if (temp1[k] & voidNum) // 当数据为无效值时，跳过本次循环
            continue;
        returnArr[index++] = temp1[k];
    }
    return returnArr;
}















