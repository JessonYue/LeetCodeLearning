//
// Created by 吴超 on 2020/8/4.
//
#include <stdlib.h>
char * toHex(int num){
    char chars[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    char* result = malloc(sizeof(char)*9);
    result[8] = '\0';
    int i=0;
    for(;i<8;i++){
        int index = num&15;
        result[7-i] = chars[index];
        num = num>>4;
        if(num==0) break;
    }
    if(i==8) i=7;
    return &result[7-i];
}
