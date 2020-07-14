package com.example.admin.myapplication.array

import kotlin.math.log10

/**
 *create by yx
 *on 2020/6/22
 */

class SolutionArrayKotlin {

    /**
     * 565. 数组嵌套
     * 索引从0开始长度为N的数组A，包含0到N - 1的所有整数。找到最大的集合S并返回其大小，其中 S[i] = {A[i], A[A[i]], A[A[A[i]]], ... }且遵守以下的规则。
     * 假设选择索引为i的元素A[i]为S的第一个元素，S的下一个元素应该是A[A[i]]，之后是A[A[A[i]]]... 以此类推，
     * 不断添加直到S出现重复的元素。
     */
    fun arrayNesting(nums: IntArray): Int {
        val length = nums.size
        if (length == 0) {
            return 0
        }

        var target = 0
        for (i in 0 until length) {
            if (nums[i] != -1) {
                var start = nums[i]
                var count = 0
                var tmp = -1
                while (nums[i] != -1) {
                    tmp = start
                    start = nums[start]
                    count++
                    nums[tmp] = -1
                }
                target = Math.max(target, count)
            }
        }

        return target
    }

    /**
     * 1295. 统计位数为偶数的数字
     * 给你一个整数数组 nums，请你返回其中位数为 偶数 的数字的个数。
     */
    fun findNumbers(nums: IntArray): Int {
        if (nums.size == 0) {
            return 0;
        }

        var result = 0
        for (i in nums) {
            if ((log10(i.toFloat()) + 1).toInt() % 2 == 0) result++
        }
        return result
    }

    /**
     * 1343. 大小为 K 且平均值大于等于阈值的子数组数目
     * 给你一个整数数组 arr 和两个整数 k 和 threshold 。
     * 请你返回长度为 k 且平均值大于等于 threshold 的子数组数目。
     */
    fun numOfSubarrays(arr: IntArray, k: Int, threshold: Int): Int {
        if (arr?.size == 0 || k < 0) {
            return 0
        }

        val sumTarget = k * threshold
        var sum = 0
        var result = 0
        for (i in 0 until k) {
            sum += arr[i]
        }

        if (sum >= sumTarget) {
            result++
        }
        for (pos in k until arr.size) {
            sum += arr[pos] - arr[pos - k]
            if (sum >= sumTarget) {
                result++
            }
        }

        return result
    }


    /**
     * 1122. 数组的相对排序
     *
     * 给你两个数组，arr1 和 arr2，
     * arr2 中的元素各不相同
     * arr2 中的每个元素都出现在 arr1 中
     * 对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。
     */
    fun relativeSortArray(arr1: IntArray, arr2: IntArray): IntArray {
        if(arr1 == null) {
            return arr1
        }

        val count = IntArray(1001)

        for (value in arr1) {
            count[value]++
        }
        var index = 0
        for (value in arr2) {
            while (count[value] > 0) {
                arr1[index] = value
                index++
                count[value]--
            }
        }

        for (i in count.indices) {
            while (count[i] > 0) {
                arr1[index] = i
                index++
                count[i]--
            }
        }
        return arr1
    }
}