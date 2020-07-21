//
// Created by 刘畅 on 2020/7/15.
//

#include "day45.h"
#include "iostream"

char *toHex(int num) {
    if (num == 0) return "0";
    char *ret, s[] = "0123456789abcdef", c;
    ret = (char *) malloc(sizeof(char) * 9);
    int i, j = 0;
    for (i = 0; i < 8 && num; i++) {
        ret[i] = s[num & 0xf];
        num >>= 4;
    }
    ret[i] = '\0';
    i--;
    while (j < i) {
        c = ret[i];
        ret[i] = ret[j];
        ret[j] = c;
        i--;
        j++;
    }
    return ret;
}

