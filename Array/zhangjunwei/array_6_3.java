package com.lanfairy.md;

import org.junit.Test;

public class array_6_3 {
    /**
     * 28. 实现 strStr() //https://leetcode-cn.com/problems/implement-strstr/
     * 实现 strStr() 函数。
     * <p>
     * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
     * <p>
     * 示例 1:
     * <p>
     * 输入: haystack = "hello", needle = "ll"
     * 输出: 2
     * 示例 2:
     * <p>
     * 输入: haystack = "aaaaa", needle = "bba"
     * 输出: -1
     * 说明:
     * <p>
     * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
     * <p>
     * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
     */
    @Test
    public void addition_isCorrect1() {
        System.out.println(strStr2("hello", "ell"));
    }

    public int strStr(String haystack, String needle) {
        int index = -1;
        if (needle.isEmpty()) return 0;
        int needleLen = needle.length();
        int haystackLen = haystack.length();
        if (needleLen > haystackLen) return index;

        for (int i = 0; i < haystackLen - needleLen + 1; i++) {
            if (haystack.substring(i, i + needleLen).equals(needle)) {
                return i;
            }
        }

        return index;

    }

    public int strStr2(String haystack, String needle) {
        int index = -1;
        if (needle.isEmpty()) return 0;
        int needleLen = needle.length();
        int haystackLen = haystack.length();
        if (needleLen > haystackLen) return index;
        //当 haystack 和 needle 第一个元素相同时才开始比较
        int h = 0;
        int l = haystackLen - needleLen + 1;

        while (h < l) {
            //定位到和needle 第一个字符相等的位置
            while (haystack.charAt(h) != needle.charAt(0)) {
                h++;
            }
            int pL = 0;
            int size = 0;
            //开始 与 needle 进行比较  pL指向 needle  h指向 haystack  size为比较相等的字符数目
            // 字符相等时
            while (pL < needleLen && h < haystackLen && needle.charAt(pL) == haystack.charAt(h)) {
                size++;
                pL++;
                h++;
            }
            //needle 字符串匹配完毕  返回needle 字符串在haystack中出现的第一个位置
            if (size == needleLen) return h - needleLen;
            h=h-size+1;
        }


        return index;
    }
}
