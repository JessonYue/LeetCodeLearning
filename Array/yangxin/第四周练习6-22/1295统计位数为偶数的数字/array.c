#include <stdio.h>

/**
 * 1295. 统计位数为偶数的数字
 * 给你一个整数数组 nums，请你返回其中位数为 偶数 的数字的个数。
 */
int findNumbers(int *nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    int result = 0, tmp = 0, bit = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            continue;
        }
        tmp = nums[i];
        bit = 0;
        while (tmp != 0) {
            tmp = tmp / 10;
            bit++;
        }
        if (bit % 2 == 0) {
            result++;
        }
    }

    return result;
}