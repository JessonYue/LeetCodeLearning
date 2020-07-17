//
// Created by 刘畅 on 2020/7/16.
//

#include "day46.h"
#include "iostream"

void moveZeroes(int *nums, int numsSize);

void moveZeroes(int *nums, int numsSize) {
    int lastNumber = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != 0) {
            nums[lastNumber] = nums[i];
            if (i != lastNumber) {
                nums[i] = 0;
            }
            lastNumber++;
        }


    }
    for (int j = 0; j < numsSize; ++j) {
        printf("%d\n", nums[j]);
    }
}

int main() {
    int nums[] = {1, 0, 3, 0, 10};
    moveZeroes(nums, 5);
    return 0;
}