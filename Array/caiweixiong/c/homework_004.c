//
// Created by Vashon on 2020/6/4.
//
#include <stdio.h>

// 面试题10.01，合并排序数组
void homework_004_1001(void) {
    void mergeArray(int *arrayA, int *arrayB, int countA, int countB);
    int m = 3, n = 3;
    int a[6] = {1, 2, 3, 0, 0, 0};
    int b[3] = {2, 5, 6};
    mergeArray(a, b, m, n);
    for (int i = 0; i < 6; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void mergeArray(int *arrayA, int *arrayB, int countA, int countB) {
    int i = 0, j = 0, lenA = countA + countB, k = lenA - 1, moveA = 0;
    while (i < lenA) {
        // 当数组a中的值小于等于数组b中的值，则索引后移，这里最好是加上等于，因为这样，数组a整体后移就可以少一次
        // 这里有一个隐藏条件，就是数组a元素已经移动完毕，这就应该直接将剩余的b数组元素插入到数组a，一开始这里没想到，掉坑了
        if (arrayA[i] <= arrayB[j] && moveA != countA) {
            i++;
            moveA++;    // 已经移动的a数组元素
        } else {
            // 数组a当前索引的值比数组b的值大，则整体后移
            // 这里有一个隐藏条件，就是数组a元素已经移动完毕，就不需要再移动后面的元素了
            while (i < k && moveA != countA) {
                arrayA[k] = arrayA[k - 1];
                k--;
            }
            // 将数组b的值插入数组a中，并且a、b索引后移一位
            arrayA[i++] = arrayB[j++];
            // 当数组b中的值都已经插入到数组a中，则结束循环
            if (j == countB)
                break;
            // 重置k为数组a最后一位的索引
            k = lenA - 1;
        }
    }
}