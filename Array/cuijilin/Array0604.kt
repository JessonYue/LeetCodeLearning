package luge

/*
2020.06.4
面试题 10.01. 合并排序的数组 //https://leetcode-cn.com/problems/sorted-merge-lcci/
给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。

初始化 A 和 B 的元素数量分别为 m 和 n。

示例:

输入:
A = [1,2,3,0,0,0], m = 3
B = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]
说明:

A.length == n + m*/

fun main() {


    var arrayA = intArrayOf(4, 6, 8, 0, 0, 0, 0, 0)
    var arrayB = intArrayOf(2, 3, 4, 5, 6)
    merge(arrayA, 3, arrayB, arrayB.size)?.forEachIndexed { index, i ->
        print("$i,")
    }

}


//  最直观的方法是先将数组 B 放进数组 A 的尾部，然后直接对整个数组进行排序。不考虑

//  双指针法：利用了数组有序的特性
fun merge(A: IntArray, m: Int, B: IntArray, n: Int): IntArray {

    var indexA = m - 1
    var indexB = n - 1
    var cur = m + n - 1
    while (indexA > -1 && indexB > -1) {
        if (A[indexA] > B[indexB]) {
            A[cur--] = A[indexA--]
        } else {
            A[cur--] = B[indexB--]
        }
    }

    while (indexB > -1) {
        A[indexB] = B[indexB]
        indexB--
    }


    return A
}
