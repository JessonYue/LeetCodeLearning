package com.slow.lib.practice.array

/**
 * 这样写，会不会被打
 * @Author wuchao
 * @Date 2020/7/14-11:14 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class RelativeSortArray {
    fun relativeSortArray(arr1: IntArray, arr2: IntArray): IntArray {
        val countArray = IntArray(1001)
        val newArray = IntArray(arr1.size)
        var index = 0
        for (item in arr1) countArray[item]++
        for (item in arr2) while (countArray[item]-- > 0) newArray[index++] = item
        for (item in countArray.indices) while (countArray[item]-- > 0) newArray[index++] = item
        return newArray
    }
}