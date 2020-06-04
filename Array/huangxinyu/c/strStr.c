//
// Created by hasee on 2020/6/3.
//
#include "alo.h"
#include <string.h>

static void getNext(const char *subStr, int next[]) {
    int i = 1;
    int j = 0;
    size_t strLen = strlen(subStr);
    next[0] = 0;
    while (j < strLen) {
        if (subStr[i] == subStr[j]) {
            j++;
            next[i] = j;
            i++;
        } else {
            if (j == 0) {
                next[i] = 0;
                i++;
            } else {
                j = next[j - 1];
            }
        }
    }
}

/**
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/implement-strstr
 */
int strStr(const char *haystack, const char *needle) {
    int needleLen = strlen(needle);
    if (needleLen > strlen(haystack)) return -1;
    if (!needle) return 0;
    int i = 0;
    int j = 0;
    int next[needleLen];
    getNext(needle, next);
    while (i < strlen(haystack)) {
        if (j == needleLen) return i - needleLen;
        if (haystack[i] == needle[j]) {
            i++;
            j++;
        } else {
            if (j != 0) {
                j = next[j - 1];
            } else {
                i++;
            }
        }
    }
    return -1;
}