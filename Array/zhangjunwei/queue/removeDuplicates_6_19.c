//
// Created by 张俊伟 on 2020/6/19.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *removeDuplicates1(char *S) {
    if (NULL == S || strlen(S) == 0)return S;
    int len = strlen(S);
    char *stack = (char *) calloc(len, sizeof(char));
    if (NULL == stack)return NULL;
    int top = -1;
    top++;
    stack[top] = S[0];
    for (int i = 1; i < len; ++i) {
        char c = S[i];
        if (stack[top] == c) {
            stack[top--] = 0;
        } else {
            stack[++top] = c;
        }
    }
    stack[++top] = '\0';
    return stack;
}

char *removeDuplicates(char *S) {
    int write = -1;
    int read = 0;
    char ch;
    while ((ch = S[read++])!='\0') {
        if (write<0){
            write = 0;
            S[0] = ch;
        } else{
            if (S[write]==ch){//出栈
                write--;
            } else{
                S[++write] = ch;//入栈
            }
        }
    }
    S[++write] = '\0';
    return S;

}

int main() {
    char s[] = {'a', 'b', 'b', 'a', 'c', 'a', 'a', 'b', 'b', 'a', 'c', 'a', 'e', '\0'};
//    printf("结果：%s  ", removeDuplicates("abbacaabba cae"));
    printf("结果：%s  ", removeDuplicates(s));
    return 0;
}