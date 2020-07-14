//
// Created by Administrator on 2020/7/13.
//
//https://leetcode-cn.com/problems/move-zeroes/
//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

//示例:
//输入: [0,1,0,3,12]
//输出: [1,3,12,0,0]

void moveZeroes(int* nums, int numsSize){
    int lastZeroIndex = numsSize -1;
    for(int i=numsSize -1; i>=0; i--){
        if(nums[i] == 0){
            for(int start =i; start<lastZeroIndex; start++){
                nums[start] = nums[start+1];
            }
            nums[lastZeroIndex] =0;
            lastZeroIndex --;
        }
    }
}