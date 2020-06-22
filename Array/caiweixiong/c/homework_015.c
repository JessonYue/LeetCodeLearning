//
// Created by Vashon on 2020/6/19.
//

#include <stdio.h>

static char carr[20000];

// 删除字符串中的所有相邻重复项，LeetCode第1047题
void homework_015_1047(void) {
    char *removeDuplicates(char *);
    char *s = "abbaca";
    s = removeDuplicates(s);
    if (s)
        printf("filter result is : %s\n", s);
    else
        printf("filter result is : null\n");
}

char *removeDuplicates(char *S) {
    if (!S)
        return NULL;
    if (*S == '\0' || S[1] == '\0') // 只有一个字符时直接返回
        return S;
    char *p = S;
    int top = -1;   // 栈顶指针
    while (*p != '\0') {
        if (top == -1)    // 栈空，直接入栈
            carr[++top] = *p++;
        else{
            if (carr[top] == *p)
                top--;
            else
                carr[++top] = *p;
            p++;
        }
    }
    carr[++top] = '\0';
    return carr;
}