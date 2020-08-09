//
// Created by LCX on 2020/8/6.
//
#include <stdio.h>
#include <string.h>
#include <malloc.h>

char * toHex(int num){
    char *s = "0123456789abcdef";
    char *index = (char*)malloc(strlen(s));
    unsigned int num1 = num;
    int top = -1;
    if(num1 == 0)
        return "0";
    while (num1 != 0)
    {
        int tmp = num1 & 15;
        index[++top] = s[tmp];
        num1 = num1 >> 4;

    }
    char *str = (char*)malloc(top+1);
    for (int i = 0; i <= top+1; ++i) {
        //printf("%c",index[top]);
        //str = str + index[top];
        str[i] = index[top];
        top--;
    }
    return str;
}


//  8    1 0  0  0
//       1 1  1  1
//       1 0  0  0
int main()
{
    //toHex(26);
    printf("to hex: %s",toHex(8));
    return 0;
}