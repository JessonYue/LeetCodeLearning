package com.slow.lib.practice.array

/**
 * @Author wuchao
 * @Date 2020/6/27-9:53 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class CountSubArraysOfAvgBiggerThanThreshold {
    fun numOfSubarrays(arr: IntArray, k: Int, threshold: Int): Int {
        var count = 0
        var i = 0
        var j = 1
        var sum = 0
        val thresholdK = threshold*k
        while (i<k){
            sum+=arr[i++]
        }
        if(sum>=thresholdK) count++
        while(i<arr.size){
            sum+=(arr[i++] - arr[j++-1])
            if(sum>=thresholdK) count++
        }
        return count
    }
}