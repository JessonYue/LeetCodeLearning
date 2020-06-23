package com.example.admin.myapplication.array

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
}