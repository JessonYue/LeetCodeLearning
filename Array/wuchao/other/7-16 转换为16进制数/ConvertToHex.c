//
// Created by 吴超 on 2020/7/16.
//
#include <stdlib.h>
char * toHex(int num){
    char chars[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    int mask = 15;
    char* result = calloc(9,sizeof(char));
    result[8] = '\0';
    int i=0;
    while(i<8){
        int bit = mask&num;
        num = ((unsigned int)num)>>4;
        if(num==0){
            if(bit>0){
                result[8-i++-1] = chars[bit];
            }
            break;
        } else {
            result[8-i++-1] = chars[bit];
        }
    }
    if(i==0){
        result[8-i++-1] = '0';
    }
    return &result[8-i];
}
