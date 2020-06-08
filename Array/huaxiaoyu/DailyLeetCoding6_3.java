package com.example.myapplication;

import org.junit.Test;

public class DailyLeetCoding6_3 {
    //2020.06.3
    //28. 实现 strStr() //https://leetcode-cn.com/problems/implement-strstr/
    //实现 strStr() 函数。
    //给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
    //示例 1:
    //输入: haystack = "hello", needle = "ll"
    //输出: 2
    //示例 2:
    //输入: haystack = "aaaaa", needle = "bba"
    //输出: -1
    //说明:
    //当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
    //对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

    @Test
    public void check() {
        System.out.println(indexOf("a", "a"));
    }

    //思路
    // 1. limit = strs.length - targets.length; 减少验证长度,如果剩余的字符长度少于needle的长度则肯定返回-1
    // 2. 将两个字符串转为数组,当找到和needle第一个匹配的字符时,循环判断needle剩余的字符是否相等
    public int indexOf(String haystack, String needle) {
        if (null == needle || null == haystack || needle.equals("")) {
            return 0;
        }

        if (haystack.length() < needle.length()) {
            return -1;
        }

        char[] strs = haystack.toCharArray();
        char[] targets = needle.toCharArray();
        int i = 0;
        int limit = strs.length - targets.length;
        while (i <= limit) {
            for (int j = 0; j < needle.length(); j++) {
                if (strs[i + j] == targets[j]) {
                    if (j == needle.length() - 1) {
                        //找到结果
                        return i;
                    }
                } else {
                    break;
                }
            }
            i++;
        }
        return -1;
    }
}
