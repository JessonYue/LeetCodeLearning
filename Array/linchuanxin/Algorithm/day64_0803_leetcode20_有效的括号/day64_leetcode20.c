//
// Created by LCX on 2020/8/6.
//

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char * s)
{
    if(*s == 0)
        return true;
    int len = strlen(s);
    if(len % 2 != 0)
        return false;
    char *stack = (char*)malloc(len);
    int top = -1;
    for (int i = 0; i < len; ++i) {
        char c = s[i];
        if(c == '(' || c == '[' || c == '{')
            stack[++top] = c;
        else{
            if(top == -1)
                return false;
            char topChar = stack[top];
            if(topChar != '(' && c == ')')
                return false;
            if(topChar != '[' && c == ']')
                return false;
            if(topChar != '{' && c == '}')
                return false;
            top--;
        }
    }
    return top == -1;
}


int main()
{
    char *s = "((";
    isValid(s);
}