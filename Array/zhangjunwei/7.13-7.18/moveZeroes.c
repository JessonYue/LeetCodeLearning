//
// Created by 张俊伟 on 2020/7/15.
//
#include <stdio.h>

void moveZeroes(int *nums, int numsSize) {
    if (nums == NULL || numsSize == 0) {
        return;
    }
    int j = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i]!=0){
            nums[j] = nums[i];
            if (i!=j)
                nums[i] = 0;
            j++;
        }
    }
}
void moveZeroes1(int *nums, int numsSize) {
    if (nums == NULL || numsSize == 0) {
        return;
    }
    int j = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i]!=0){
            nums[j++] = nums[i];
        }
    }
    for (int k = j; k < numsSize; ++k) {
        nums[k] = 0;
    }
}
int main(){
    int t[] = {0,1,0,3,12};
    moveZeroes(t, 5);
    t;
}