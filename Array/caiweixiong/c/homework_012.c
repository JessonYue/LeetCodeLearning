//
// Created by Vashon on 2020/6/16.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// 有效的括号，LeetCode第20题
void homework_012_020(void) {
    char *str = "((()))";
    int isValid_(char *s);
    if (isValid_(str))
        printf("success");
    else
        printf("failure");
}

int isValid(char *s) {
    // 用栈的思想，后进先出，完美解决这个匹配问题
    if (!s || *s == '\0')     // 空字符串，匹配
        return 1;
    char *str = s;
    int len = strlen(s), top = -1;
    if (len & 1)   // 括号应该是成对出现的，单个肯定是不匹配的
        return 0;
    char stack[len];
    for (int i = 0; i < len; ++i, str++) {
        if (*str == '(' || *str == '{' || *str == '[') {
            stack[++top] = *str;    // 左括号，入栈
        }
        if (top == -1)              // 第一个元素不是左括号，不匹配
            return 0;
        if (*str == ')') {
            if (stack[top] == '(')
                stack[top--] = '\0';// 出栈
            else
                return 0;
        }
        if (*str == '}') {
            if (stack[top] == '{')
                stack[top--] = '\0';
            else
                return 0;
        }
        if (*str == ']') {
            if (stack[top] == '[')
                stack[top--] = '\0';
            else
                return 0;
        }
    }
    return top == -1 ? 1 : 0;
}

// 本来是使用这种方法的，但是LeetCode上报错，说内存溢出了，但是感觉没有写错，只是动态扩容了
int isValid_(char *s) {
    if (!s || *s == '\0')
        return 1;
    int index = -1, length = 10;    // 起始的分配空间大小
    float scale = 1.5;              // 扩容的比例因子
    char *str = s, *brackets = malloc(sizeof(char) * length);

    while (*str != '\0') {
        if (index == length - 1) {  // 分配的空间不够，重新分配，每次扩容为原来的1.5倍
            length *= scale;
            brackets = realloc(brackets, sizeof(char) * length);
        }
        if (*str == '(' || *str == '{' || *str == '[') {
            brackets[++index] = *str;
        }
        if (index == -1)            // 第一个元素不是左括号，不匹配
            return 0;
        if (*str == ')') {
            if (brackets[index] == '(')
                brackets[index--] = '\0';
            else
                return 0;
        }
        if (*str == '}') {
            if (brackets[index] == '{')
                brackets[index--] = '\0';
            else
                return 0;
        }
        if (*str == ']') {
            if (brackets[index] == '[')
                brackets[index--] = '\0';
            else
                return 0;
        }
        str++;
    }
    free(brackets);
    return index == -1 ? 1 : 0;
}
