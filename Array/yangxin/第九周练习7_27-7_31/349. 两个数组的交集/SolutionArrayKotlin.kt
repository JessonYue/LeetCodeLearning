package com.example.admin.myapplication.array

import kotlin.math.log10

/**
 *create by yx
 *on 2020/6/22
 */

class SolutionArrayKotlin {

    /**
     * 349. 两个数组的交集
     * 给定两个数组，编写一个函数来计算它们的交集。
     */
    fun intersection(nums1: IntArray, nums2: IntArray): IntArray {
        val set1 = HashSet<Int>()
        val set2 = HashSet<Int>()

        for ( i in nums1) {
            set1.add(i)
        }
        for ( i in nums2) {
            set2.add(i)
        }
        var list = mutableListOf<Int>()
        for (i in set1) {
            if (set2.contains(i)) list.add(i)
        }

        return list.toIntArray()
    }
}