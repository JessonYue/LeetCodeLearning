//
// Created by Vashon on 2020/7/17.
//

#ifndef C_STRING_UTILS_H
#define C_STRING_UTILS_H

// 字符串复制函数
char *my_strcpy(char *dest, const char *src);

// 字符串拼接函数
char *my_strcat(char *dest, const char *src);

// 字符串包含小串
char *my_strstr(const char *haystack, const char *needle);

// 字符串包含字符
char *my_strchr(const char *str, int c);

// 数组复制
void *my_memcpy(void *str1, const void *str2, size_t n);

#endif //C_STRING_UTILS_H
