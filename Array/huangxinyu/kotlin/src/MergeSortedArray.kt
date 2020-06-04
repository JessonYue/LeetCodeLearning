package com.ryujin.algorithm

/**
 *  给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。
初始化 A 和 B 的元素数量分别为 m 和 n。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sorted-merge-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
class MergeSortedArray {
    companion object {
        /**
         * a[0]<b[0]
         */
        fun test1() {
            val a = intArrayOf(1, 2, 3, 0, 0, 0)
            val b = intArrayOf(2, 5, 6)
            merge1(a, 3, b, 3)
            a.forEach { print(it) }
        }

        /**
         * a[0]>b[0]
         */
        fun test2() {
            val a = intArrayOf(2, 3, 4, 0, 0, 0)
            val b = intArrayOf(1, 3, 5)
            merge1(a, 3, b, 3)
            a.forEach { print(it) }
        }

        /**
         * b数组开始位置有多个小于a[0]
         */
        fun test3() {
            val a = intArrayOf(5, 6, 7, 0, 0, 0)
            val b = intArrayOf(1, 3, 4)
            merge1(a, 3, b, 3)
            a.forEach { print(it) }
        }

        /**
         * 方法1：借助一个m+n长度的数组c，两个指针分别指向两个数组的起始位置，每次将较小的数填充进c数组中，
         * 然后将剩余数据的后面的数据全部拷贝进去，最后再将c数组数据复制给A数组
         */
        fun merge(A: IntArray, m: Int, B: IntArray, n: Int) {
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
            c.forEachIndexed { index, i ->
                A[index] = i;
            }
        }

        /**
         * 方法2：同方法1的思路差不多，不过用到三个指针，cur指针指向A数组的m+n-1位置，ida指针指向A数组有效数据的末尾，idb指向B数组
         * 有效数据的末尾，一次比较ida和idb指向的数据，将大的那个数据赋值给cur指针指向的位置，然后cur--，较大的那个指针--
         */
        fun merge1(A: IntArray, m: Int, B: IntArray, n: Int) {
            var cur = m + n - 1
            var ida = m - 1
            var idb = n - 1
            while (idb >= 0 && ida >= 0) {
                A[cur--] = if (A[ida] >= B[idb]) A[ida--] else B[idb--]
            }
            while (idb >= 0) {
                A[cur--] = B[idb--]
            }
        }
    }
}
