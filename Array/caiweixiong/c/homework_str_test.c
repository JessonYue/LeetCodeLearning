//
// Created by Vashon on 2020/7/17.
//

#include <stdio.h>
#include "string_utils.h"

void homework_str_test(void) {
    // 字符串复制函数测试
//    char *src = "hello strcpy";
//    char dest[13] = {'\0'};
//    printf("dest : %s\n", my_strcpy(dest, src));

    // 字符串拼接函数测试
//    char *src = "hello strcpy";
//    char dest[20] = "dest ";
//    printf("dest : %s\n", my_strcat(dest, src));

    // 字符串包含小串测试
//    char *haystack = "hello strcpy";
//    char *needle = "cpy";
//    printf("needle : %s\n", my_strstr(haystack, needle));

    // 字符串包含字符测试
//    char *str = "http://www.baidu.com";
//    char ch = '.';
//    printf("ch after : %s\n", my_strchr(str, ch));

    // 数组复制测试
    char *src = "hello memcpy";
    char dest[20] = {'\0'};
    my_memcpy(dest, src, 13);
    printf("dest : %s\n", dest);
}

char *my_strcpy(char *dest, const char *src) {
    if (!dest || !src)
        return NULL;
    char *d = dest, *s = src;
    while (*s != '\0')*d++ = *s++;
    return dest;
}

char *my_strcat(char *dest, const char *src) {
    if (!dest || !src)
        return NULL;
    char *d = dest, *s = src;
    while (*d != '\0')d++;
    while (*s != '\0')*d++ = *s++;
    return dest;
}

char *my_strstr(const char *haystack, const char *needle) {
    if (!haystack || !needle)
        return NULL;
    // 步骤：
    // 1.用两个指针指向大串，用一个指针指向小串
    // 2.当大串与小串起始字符不匹配，则两个指针一直后移
    // 3.当大串匹配小串，则大串一个指针不变，一个指针后移，同时小串指针后移
    // 4.若第 3 步出现不匹配，则大串起始指针后移一位，另外的指针同时重置到当前位置，小串指针重置，回到第 3 步，直到到达大串结尾
    char *hpre = haystack, *hnext = haystack, *np = needle;
    while (*hpre != '\0') {
        if (*np == '\0')
            return needle;
        if (*hnext == '\0') // 大串到达了字符串结尾，仍然没匹配到的小串，结束
            return NULL;
        if (*hnext == *np)
            hnext++, np++;
        else {
            hpre++;
            hnext = hpre;
            np = needle;
        }
    }
    return NULL;
}

char *my_strchr(const char *str, int c) {
    if (!str)
        return NULL;
    char *s = str;
    while (*s != '\0') {
        if (*s == c)
            return s;
        s++;
    }
    return NULL;
}

void *my_memcpy(void *str1, const void *str2, size_t n) {
    if (!str2 || !str1 || n <= 0)
        return NULL;
    char *s1 = str1, *s2 = str2;
    for (int i = 0; i < n; *s1++ = *s2++, ++i);
}





























