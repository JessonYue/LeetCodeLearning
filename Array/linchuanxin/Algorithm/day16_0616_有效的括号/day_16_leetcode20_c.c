//
// Created by LCX on 2020/6/15.
//
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

bool isValid(char * s){
    if(*s == 0)  //空字符 符合
    return true;
    int len = strlen(s);
    // if (a%2)
    if(len & 1)  //奇数  不符合
    return false;
    char* stack=(char *) malloc (len);
    int top = -1;
    for(int i = 0 ; i < len; ++i)
    {
        char c = s[i];
        if(c == '('||c == '['||c == '{')
        {
            stack[++top] = c;
        }
        else
        {
            if(top == -1)
                return false;
            char topChar = stack[top];
            if(c == ')' && topChar != '(')
                return false;
            if(c == ']' && topChar != '[')
                return false;
            if(c == '}' && topChar != '{')
                return false;
            top--;
        }
    }
    return top == -1;
}



int main(){
    char *s = "{}}";
    if(isValid(s)){
        printf("成立");
    }else{
        printf("不成立");
    }
    return 0;
}
