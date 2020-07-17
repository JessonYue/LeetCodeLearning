package com.slow.lib.practice.array

/**
 * @Author wuchao
 * @Date 2020/7/17-4:54 PM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class MoveZero {
    fun moveZeroes(nums: IntArray): Unit {
        var lastNoZeroIndex = 0
        for(item in nums){
            if(item==0){
                continue
            }
            nums[lastNoZeroIndex++] = item
        }
        for(index in lastNoZeroIndex until nums.size){
            nums[index] = 0
        }
    }
}