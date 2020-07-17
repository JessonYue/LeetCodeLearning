//
// Created by 吴超 on 2020/7/17.
//
void moveZeroes(int* nums, int numsSize){
    int lastNoZeroIndex = 0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]==0){
            continue;
        }
        nums[lastNoZeroIndex++] = nums[i];
    }
    for(int i=lastNoZeroIndex;i<numsSize;i++){
        nums[i] = 0;
    }
}
