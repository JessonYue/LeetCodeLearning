//
// Created by Vashon on 2020/6/24.
//

#include <stdio.h>

// 统计位数为偶数的数字，LeetCode第1295题
void homework_017_1295(void) {
    int findNumbers(int *nums, int numsSize);
    int nums[] = {12, 345, 2, 6, 7896};
    printf("the double bit num have : %d", findNumbers(nums, 5));
}

int findNumbers(int *nums, int numsSize) {
    if (!nums || numsSize <= 0)
        return 0;
    int count = 0, bit = 0, temp = 0;
    for (int i = 0; i < numsSize; ++i) {
        bit = 0;
        temp = nums[i];
        do {
            temp /= 10;
            bit++;
        } while (temp != 0);
        if ((bit % 2) == 0)
            count++;
    }
    return count;
}