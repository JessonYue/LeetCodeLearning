package luge


/***
给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:
输入: haystack = "hello", needle = "ll"
输出: 2

示例 2:
输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 */

fun main() {

    var haystack = "world hello"
    var needle = "ll"

    println(strStr(haystack, needle))

}


// 暴力解法
fun strStr(haystack: String, needle: String): Int {

    var L = haystack.length
    var n = needle.length

    for (i in 0..L - n) {
        if (haystack.substring(i, i + n) == needle) {
            return i
        }
    }

    return 0
}

/* 方法二：双指针 - 线性时间复杂度 */
fun strStr2(haystack: String, needle: String): Int {


    return 0

}