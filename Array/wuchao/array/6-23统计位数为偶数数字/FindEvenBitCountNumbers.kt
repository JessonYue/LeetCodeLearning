package com.slow.lib.practice.array

/**
 * @Author wuchao
 * @Date 2020/6/23-10:22 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class FindEvenBitCountNumbers {
    fun findNumbers(nums: IntArray): Int {
        var count = 0
        for(item in nums){
            val bitCount = getBitCounts(item)
            if((getBitCounts(item) and 1) ==0){
                count++
            }
        }
        return count
    }

    fun getBitCounts(num:Int): Int {
        var count = 1
        var temp = num/10
        while(temp>=1){
            temp/=10
            count++
        }
        return count
    }
}