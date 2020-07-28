package com.slow.lib.practice.array

import java.util.*

/**
 * @Author wuchao
 * @Date 2020/7/28-10:01 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class FindArrayIntersection {
    fun intersection(nums1: IntArray, nums2: IntArray): IntArray {
        val maps1 = HashMap<Int,Int>()
        val maps2 = HashMap<Int,Int>()
        for(item in nums1){
            maps1[item] = 1
        }
        for(item in nums2){
            if(maps1.containsKey(item)){
                maps2[item] = 1
            }
        }
        val intersection = IntArray(maps2.size)
        var i = 0
        for(item in maps2.keys){
            intersection[i++] = item
        }
        return intersection
    }
}