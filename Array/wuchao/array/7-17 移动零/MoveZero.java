package com.slow.lib.practice.array;

/**
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 这题思路的关键是非0的元素数量只可能小于等于数组大小，那么可以遍历数组，将所有非0的元素填充到数组的头部，这样也是按顺序的。
 * 注意这样操作并不会导致元素被覆盖从而导致元素缺少，理由上面说了，因为非0元素数量只可能小于等于数组大小。
 * 记录最后一个非0元素的下一个元素数组下标，从这个下标开始一直到数组尾部都填充0即可。
 * @Author wuchao
 * @Date 2020/7/17-4:46 PM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class MoveZero {
    public void moveZeroes(int[] nums) {
        int lastNoZeroIndex = 0;
        for(int item:nums){
            if(item==0){
                continue;
            }
            nums[lastNoZeroIndex++] = item;
        }
        for(int i=lastNoZeroIndex;i<nums.length;i++){
            nums[i] = 0;
        }
    }
}
