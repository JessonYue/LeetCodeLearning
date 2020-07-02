package com.lanfairy.md.july

class Solution628 {
    /**https://leetcode-cn.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/solution/ci-ti-zui-you-jie-hua-dong-chuang-kou-jia-dong-tai/
     * 思路：
    step1 ： 取出前k个数求和，然后减去k*threshold ，如果结果大于0，说明符合要求。
    step2 ： 指针后移一位，用后移一位的值减去移动之前的第一位的值，再加上上次减法的结果，如果大于0，说明符合要求

    整体思路没有除法，只有增量的加减，而且加减数值非常小。
     */
    fun numOfSubarrays(arr: IntArray, k: Int, threshold: Int): Int {
        var count = 0
        var i = 0
        var sum = 0
        while (i < k) {
            sum += arr[i]
            i++
        }
        var t = sum - k * threshold
        if (t >= 0)
            count++
        var len = arr.size - k
        var pos = k
        i = 0
        while (i < len) {
            t = arr[pos] - arr[i] + t
            if (t >= 0)
                count++
            pos++
            i++
        }

        return count
    }
}

fun main() {
    var arr = intArrayOf(2, 2, 2, 2, 5, 5, 5, 8)
    var count = Solution628().numOfSubarrays(arr, 3, 4)
    print(count)
}