#include <stdio.h>
#include <stdlib.h>

int findNumbers(int *nums, int numsSize);

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