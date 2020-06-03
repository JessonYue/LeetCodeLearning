package com.github.leetcode.p0028_implement_strstr;

/**
 * https://leetcode-cn.com/problems/implement-strstr/
 * <p>
 * 实现 strStr() 函数。
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
 * <p>
 * 示例：
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 说明:
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * <p>
 * 时间复杂度在 O()
 */
class Solution {
    /**
     * --------------------我的代码--------------------
     */
   /* public int strStr(String haystack, String needle) {
        // 1. 进行前置判断
        // 1.1 needle是空字符串时
        if (needle == null || needle.length() == 0) {
            return 0;
        }
        // 1.2 如果needle长度比haystack的还要大直接返回-1
        if (haystack == null || haystack.length() < needle.length()) {
            return -1;
        }
        //2. 开始真正的查找查找
        boolean isFind = false;//是否找到的标志位
        int findIndex = -1;//记录位置的index
        for (int i = 0; i < haystack.length(); i++) {// helalollxps
            //如果(haystack.length-i)长度小于needle的长度，则直接返回-1
            if (haystack.length() - i < needle.length()) {
                return -1;
            }
            int tempIndex = i;//临时变量，记录当前已经找到的位置
            for (int j = 0; j < needle.length(); j++) {// xpsz
                if (needle.charAt(j) == haystack.charAt(tempIndex)) {
                    findIndex = i;
                    tempIndex++;
                    if (j == needle.length() - 1) {
                        isFind = true;
                    }
                } else {
                    isFind = false;
                    break;
                }
            }
            if (isFind) {
                return findIndex;
            }
        }
        return -1;
    }*/
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println("index:" + solution.strStr("a", "a"));
        System.out.println("index:" + solution.strStr("helalollxps", "ll"));
    }

    /**
     * --------------------别人的代码--------------------
     */
    //String#indexOf源码方法
    public int strStr(String haystack, String needle) {
        return haystack.indexOf(needle);
    }
}