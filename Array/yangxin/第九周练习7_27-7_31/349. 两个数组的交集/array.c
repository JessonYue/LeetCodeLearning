//
// Created by 12 on 2020/5/31.
//

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>



/**
 * 349. 两个数组的交集
 * 给定两个数组，编写一个函数来计算它们的交集。
 */

int notInclude(int* array,int size, int val) {
    for (int i= 0; i < size; i++) {
        if (array[i] == val) {
            return 0;
        }
    }
    return 1;
}

int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize) {
    if (nums1Size == 0 || nums2Size == 0) {
        *returnSize = 0;
        return NULL;
    }

    int size = nums1Size < nums2Size ? nums1Size : nums2Size;
    int *array = malloc(sizeof(int) * size);
    int index = 0;

    for(int i = 0 ; i < nums2Size; i++) {
        for (int j = 0; j < nums1Size; j++) {
            if (nums2[i] == nums1[j] && notInclude(array, index, nums2[i])) {
                array[index++] = nums2[i];
                break;
            }
        }
    }
    *returnSize = index;
    return array;
}
