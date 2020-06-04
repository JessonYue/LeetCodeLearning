package com.company;

/**
 实现 strStr() 函数。

 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

 示例 1:

 输入: haystack = "hello", needle = "ll"
 输出: 2
 示例 2:

 输入: haystack = "aaaaa", needle = "bba"
 输出: -1
 说明:

 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 */

/**
 * 实现思路：
 * 1、先找到第一个匹配的字符
 * 2、拿着匹配的字符，开始匹配后面的子串
 */
public class _0603 {
    public static  void main(String args[]){
        System.out.println(strStr("hellozhang",""));
    }

    /**
     * 获取子串
     * @param haystack
     * @param needle
     * @return
     */
    public static int strStr(String haystack, String needle) {
        if (needle == null || needle.length()==0){
            return 0;
        }
        char[] sources = haystack.toCharArray();
        char[] targets = needle.toCharArray();
        int needleLegth= needle.length();
        int i =0;
        int needStep =0;
        //需要遍历的长度，总串-字串就行
        int sourceLength = sources.length-needleLegth;
        for (;i<=sourceLength;i++){
            //找到第一个字符
            if (sources[i]!=targets[needStep]){
                ++i;
                while(i<= sourceLength && sources[i]!=targets[needStep]){
                        ++i;
                }
            }
            //只要不超过sourceLength，说明第一个字符找到了
            if (i<=sourceLength){
                //开始匹配该字符后面的所有字符
                int sourceIndex = i+1;
                int childIndex = 1;
                for (;childIndex<needleLegth;childIndex++){
                    if (targets[childIndex]!=sources[sourceIndex]){
                        break;
                    }
                    sourceIndex++;
                }
                //说明已经跑到了最后，找到子串
                if (childIndex==needleLegth){
                    return i;
                }

            }
        }
        return -1;
    }
}
