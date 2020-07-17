//
// Created by Vashon on 2020/7/9.
//

#include <stdio.h>

// 方法一：双指针法
void reverseString(char *s, int sSize);

// 方法二：递归
void reverseString_(char *s, int sSize);

// 递归
void reverse(int left, int right, char *s);

// 反转字符串，LeetCode第344题
void homework_026_344(void) {
    char str[] = "hello";
    printf("reverse before str : %s\n", str);
    reverseString_(str, 5);
    printf("reverse after str : %s\n", str);
}

void reverseString(char *s, int sSize) {
    if (!s || sSize <= 0)
        return;
    int end = sSize - 1, start = 0;
    while (end > start) {
        if (s[end] != s[start]) {   // 不一样的字符进行转换
            char temp = s[end];
            s[end] = s[start];
            s[start] = temp;
        }
        end--, start++;
    }
}

void reverseString_(char *s, int sSize) {
    if (!s || sSize <= 0)
        return;
    reverse(0, sSize - 1, s);
}

void reverse(int left, int right, char *s) {
    if (left < right) {
        if (s[right] != s[left]) {   // 不一样的字符进行转换
            char temp = s[right];
            s[right] = s[left];
            s[left] = temp;
        }
        reverse(left + 1, right - 1, s);
    }
}