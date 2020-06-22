#include <stdio.h>
#include <malloc.h>

/**
 * 565. 数组嵌套
 * 索引从0开始长度为N的数组A，包含0到N - 1的所有整数。找到最大的集合S并返回其大小，
 * 其中 S[i] = {A[i], A[A[i]], A[A[A[i]]], ... }且遵守以下的规则。
 * 假设选择索引为i的元素A[i]为S的第一个元素，S的下一个元素应该是A[A[i]]，之后是A[A[A[i]]]... 以此类推，不断添加直到S出现重复的元素。
 *
 * 注意：题目要求找到其中最大的一组
 */
int max(int a, int b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

int arrayNesting(int *nums, int numsSize) {
    if (nums == NULL || numsSize == 0) {
        return 0;
    }

    char *map = calloc(numsSize, sizeof(char));
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        if (map[i] != 1) {
            int start = nums[i], count = 0;
            do {
                start = nums[start];
                map[start] = 1;
                count++;
            } while (start != nums[i]);
            result = max(result, count);
        }
    }
    free(map);
    return result;
}