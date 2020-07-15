#include <stdio.h>
/**
 * 283. 移动零
 *给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 */
void moveZeroes(int *nums, int numsSize) {
    if (nums == NULL) {
        return;
    }

    int tail = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[tail++] = nums[i];
        }
    }

    for (int i = tail; i < numsSize; i++) {
        nums[i] = 0;
    }
}