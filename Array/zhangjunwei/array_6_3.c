//
// Created by 张俊伟 on 2020/6/3.
//

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
#include <stdio.h>
#include <string.h>
int strStr1(char *haystack, char *needle);
int main() {
    char *haystack = "hello";
    char *needle = "lo";
    printf("%d",strStr1(haystack, needle)) ;
    return 0;
}

int strStr1(char *haystack, char *needle) {
    if (needle==NULL)return -1;
    if(strlen(needle)==0)return 0;
    int neeLen = strlen(needle);
    int hayLen = strlen(haystack);
    if (neeLen>hayLen)return -1;
    int l = hayLen-neeLen+1;
    int ph = 0;
    while (ph<l){
        //定位开始比较的位置  haystack 中与 needle 首字符相等的 位置
        while (haystack[ph] != needle[0])
            ph++;
        int size = 0;
        int pn = 0;
        while (pn<neeLen && ph<hayLen && needle[pn]==haystack[ph]){
            pn++;
            ph++;
            size++;
        }
        if (size==neeLen)return ph-neeLen;
        ph = ph-size+1;
    }
    return -1;
}