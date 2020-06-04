package com.ryujin.algorithm

class MergeSortedArray {
    companion object {
        fun test1() {
            val a = intArrayOf(1, 2, 3, 0, 0, 0)
            val b = intArrayOf(2, 5, 6)
            val c: IntArray = merge(a, 3, b, 3)
            c.forEach { print(it) }
        }


        /**
         *  给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。
        初始化 A 和 B 的元素数量分别为 m 和 n。
        来源：力扣（LeetCode）
        链接：https://leetcode-cn.com/problems/sorted-merge-lcci
        著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
         */
        fun merge(A: IntArray, m: Int, B: IntArray, n: Int): IntArray {
            val c = IntArray(m + n)
            var i = 0
            var j = 0
            var index = 0
            while (i < m && j < n) {
                if (A[i] <= B[j]) {
                    c[index] = A[i]
                    ++i
                } else {
                    c[index] = B[j]
                    ++j
                }
                ++index
            }
            //将剩余的部分依次放入数组中
            if (i < m) {
                System.arraycopy(A, i, c, index, m - i)
            }
            if (j < n) {
                System.arraycopy(B, j, c, index, n - j)
            }
            return c
        }
    }
}
