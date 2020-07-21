//
// Created by 张俊伟 on 2020/7/14.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//
//char *toHex1(int num) {
//    char p[9] = {0};
//    int tp = num;
//    if (tp < 0)
//        tp = (tp) & (0x7fffffff);
//    unsigned char bits = 0;
//    do {
//        p[bits++] = tp & 0xf;
//        tp >>= 4;
//        if (bits >= 8)
//            break;
//    }while (tp);
//    if (bits >= 8)
//        p[bits - 1] += 8;
//
//    char *res = (char *) calloc((bits + 1), sizeof(char));
//    for (int i = 0; i < bits; ++i) {
//        if (p[bits - 1 - i] >= 10)
//            res[i] = p[bits - 1 - i] - 10 + 'a';
//        else
//            res[i] = p[bits - 1 - i]+'0';
//    }
//
//    return res;
//}

char *toHex(int num) {
    char table[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    int idx = 7, tp = num;

    char *res = (char *) calloc(9, sizeof(char));
    do {
        res[idx--] = table[tp & 0xf];
        tp >>= 4;
    } while (tp != 0 && idx >= 0);
    return res + idx + 1;
}

int main() {
    char *str = toHex(1000000);
    printf("%s", str);
}