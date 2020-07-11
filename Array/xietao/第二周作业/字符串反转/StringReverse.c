//
// Created by 谢涛 on 2020/7/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void reverString(char *string){
    char *p = NULL, *q = NULL;
    int size = strlen(string);
    p = string;
    q = string + size -1;
    while (p < q){
        char c = *p;
        *p = *q;
        *q = c;
        ++p;
        --q;
    }
}

int main(){
    char string[] = "xie1tao";
    printf("反转前=%s\n",string);
    reverString(string);
    printf("反转后=%s\n",string);

    return 1;
}

