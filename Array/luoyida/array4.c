#include <stdio.h>
#include "stdlib.h"
#include <string.h>

/**
2020.06.4
面试题 10.01. 合并排序的数组 //https://leetcode-cn.com/problems/sorted-merge-lcci/
给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。

初始化 A 和 B 的元素数量分别为 m 和 n。

示例:

输入:
A = [1,2,3,0,0,0], m = 3
B = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]
说明:

A.length == n + m
**/

int main() {
    int a[] = {1, 2, 3};
    int b[] = {2, 5, 6};
    int lengthA = sizeof(a) / sizeof(a[0]);
    int lengthB = sizeof(b) / sizeof(b[0]);
    int c[lengthA + lengthB];
    int lengthC = sizeof(c) / sizeof(c[0]);
    printf("Hello, World!\n");
    for (int j = 0; j < lengthA; j++) {
        c[j] = a[j];
    }
    for (int i = 0; i < lengthC; i++) {
        c[i + lengthA] = b[i];
    }

    insert_sort(c, lengthC);

    printf("Hello, World!\n");

}

int insert_sort(int a[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = a[i];
        for (j = i; j > 0; j--) {
            if (temp < a[j - 1]) {
                a[j] = a[j - 1];
            } else {
                break;
            }
        }
        a[j] = temp;
    }
    for (int k = 0; k < n; k++) {
        printf("%d ", a[k]);
    }
}

