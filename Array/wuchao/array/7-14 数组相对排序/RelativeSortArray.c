//
// Created by 吴超 on 2020/7/14.
//
#include <stdlib.h>

int *relativeSortArray(int *arr1, int arr1Size, int *arr2, int arr2Size, int *returnSize) {
    *returnSize = arr1Size;
    int *newArray = (int*)malloc(arr1Size*sizeof(int));
    //注意这里需要调用calloc ，除非手动将元素都置为0，因为这个计数需要从0开始，而不是简单的存储数据
    int *countArray = calloc(1001, sizeof(int));
    int index = 0;
    for (int i = 0; i < arr1Size; i++)countArray[arr1[i]]++;
    for (int i = 0; i < arr2Size; i++) while (countArray[arr2[i]]-- > 0) newArray[index++] = arr2[i];
    for (int i = 0; i < 1001; i++) while (countArray[i]-- > 0) newArray[index++] = i;
    return newArray;
}

