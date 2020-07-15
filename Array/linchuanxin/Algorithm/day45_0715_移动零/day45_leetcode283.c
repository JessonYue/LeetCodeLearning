//
// Created by LCX on 2020/7/15.
//

#include <stdio.h>

void moveZeroes(int* nums, int numsSize){

    if(nums == NULL)
        return;
    int j = 0;
    int k;
    for (k = 0; k < numsSize; ++k) {
        if(nums[k]!=0)
        {
            int temp = nums[k];
            nums[k] = nums[j];
            nums[j++] = temp;
        }
    }

}