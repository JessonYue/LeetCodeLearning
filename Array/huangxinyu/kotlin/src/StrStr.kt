package com.ryujin.algorithm

/**
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/implement-strstr
 *
 * 理解视频：https://www.bilibili.com/video/BV1jb411V78H
 */
class StrStr {
    companion object {
        /**
         * haystack为空字符
         */
        private fun test1() {
            assert(strStr("", "a") == -1)
        }

        /**
         * needle为空字符
         */
        private fun test2() {
            assert(strStr("a", "") == 0)
        }

        /**
         * needle比haystack长
         */
        private fun test3() {
            assert(strStr("a", "ab") == -1)
        }

        /**
         * needle不在haystack中
         */
        private fun test4() {
            assert(strStr("abcd", "abe") == -1)
        }

        /**
         * needle在haystack中
         */
        private fun test5() {
            assert(strStr("abcd", "bc") == 1)
        }

        fun test() {
            test1()
            test2()
            test3()
            test4()
            test5()
        }

        private fun getNext(str: String): IntArray {
            val next = IntArray(str.length)
            next[0] = 0
            var i = 1
            var j = 0
            while (i < str.length) {
                if (str[i] == str[j]) {
                    j++
                    next[i] = j
                    i++
                } else {
                    if (j == 0) {
                        next[i] = 0;
                        i++
                    } else {
                        j = next[j - 1];
                    }
                }
            }
            return next
        }

        private fun strStr(haystack: String, needle: String): Int {
            if (needle.length > haystack.length) return -1;
            if ("" == needle) return 0;
            var i = 0
            var j = 0
            val next = getNext(needle)
            while (i < haystack.length) {
                if (j == needle.length) {
                    return i - needle.length
                }
                if (haystack[i] == needle[j]) {
                    i++
                    j++
                } else {
                    if (j != 0) {
                        j = next[j - 1]
                    } else {
                        i++;
                    }
                }
            }

            return -1
        }
    }
}