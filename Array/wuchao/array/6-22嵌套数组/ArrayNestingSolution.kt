package com.slow.lib.practice.array

/**
 * @Author wuchao
 * @Date 2020/6/22-10:36 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class ArrayNestingSolution {
    fun arrayNesting(nums: IntArray): Int {
        var max = 0
        for (i in 0..nums.size -1) {
            var count = 0
            var sItemIndex: Int = i
            while (nums[sItemIndex] != -1) {
                count++
                val temp = sItemIndex
                sItemIndex = nums[sItemIndex]
                nums[temp] = -1
            }
            max = Math.max(count, max)
        }
        return max
    }
}