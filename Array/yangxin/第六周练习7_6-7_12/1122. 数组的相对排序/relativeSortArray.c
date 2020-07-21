#include <stdio.h>

/**
 * 1122. 数组的相对排序
 * 给你两个数组，arr1 和 arr2，
 * arr2 中的元素各不相同arr2 中的每个元素都出现在 arr1 中对 arr1 中的元素进行排序，
 * 使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。
 */

//插入排序
int *insertSort(int *arr, int start, int size) {
    if (arr == NULL || size == 0 || start < 0) {
        return arr;
    }
    int tmp;
    for (int i = start; i < size; i++) {
        int index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[index] > arr[j]) {
                index = j;
            }
        }
        if (index == i) {
            continue;
        }
        tmp = arr[i];
        arr[i] = arr[index];
        arr[index] = tmp;
    }

    return arr;
}

int *relativeSortArray(int *arr1, int arr1Size, int *arr2, int arr2Size, int *returnSize) {
    *returnSize = arr1Size;
    if (arr1 == NULL || arr1Size == 0) {
        return arr1;
    }

    if (arr2 == NULL || arr2Size == 0) {

        return insertSort(arr1, 0, arr1Size);
    }

    int tmpIndex = 0;
    int tmpVal;
    for (int i = 0; i < arr2Size && tmpIndex < arr1Size; i++) {
        for (int j = tmpIndex; j < arr1Size; j++) {
            if (arr1[j] == arr2[i]) {
                if (tmpIndex < j) {
                    tmpVal = arr1[tmpIndex];
                    arr1[tmpIndex] = arr1[j];
                    arr1[j] = tmpVal;
                }
                tmpIndex++;
            }
        }
    }

    if (tmpIndex == arr1Size) {
        return arr1;
    }

    insertSort(arr1, tmpIndex, arr1Size);
    return arr1;
}