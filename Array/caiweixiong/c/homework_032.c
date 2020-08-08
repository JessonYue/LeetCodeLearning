//
// Created by Vashon on 2020/7/15.
//


#include "homework_032.h"

char *toHex_1(int num) {
    if (num == 0) return "0\0";
    // 一个十六进制数由 4 位二级制数组成，而一个字节有 8 位，所以最大需要开辟的空间就是数据类型字节数的两倍(一字节可以表示2个十六进制数)
    const int length = sizeof(int) << 1;
    int index = length - 1;
    char temp[length];
    unsigned int quotient = num; // 除以 16 得到的值，这里强制转成无符号数，可以避免负数的判断
    int mod, hex = 0xf;          // 对 16 取模的余数
    while (quotient) {
        mod = quotient & hex;
        temp[index--] = getHexChar(mod);
        quotient >>= 4;
    }
    // 动态开辟的数组要多一个字符串结束标记，所以多一位
    int size = length - index;
    char *hexStr = malloc(size), *p = hexStr;
    hexStr[size - 1] = '\0';
    // 将实际有用的数据存到动态开辟的数组内
    for (int i = index + 1; i < length; *p++ = temp[i], ++i);
    return hexStr;
}

char getHexChar(int value) {
    switch (value) {
        case 0:
            return 48;  // 0
        case 1:
            return 49;  // 1
        case 2:
            return 50;  // 2
        case 3:
            return 51;  // 3
        case 4:
            return 52;  // 4
        case 5:
            return 53;  // 5
        case 6:
            return 54;  // 6
        case 7:
            return 55;  // 7
        case 8:
            return 56;  // 8
        case 9:
            return 57;  // 9
        case 10:
            return 97;  // a
        case 11:
            return 98;  // b
        case 12:
            return 99;  // c
        case 13:
            return 100; // d
        case 14:
            return 101; // e
        case 15:
            return 102; // f
        default:
            return 0;
    }
}

char *toHex_2(int num) {
    if (num == 0) return "0\0";
    // 一个十六进制数由 4 位二级制数组成，而一个字节有 8 位，所以最大需要开辟的空间就是数据类型字节数的两倍(一字节可以表示2个十六进制数)
    unsigned int eleSize = sizeof(int), strIndex = 0, moveBit = (eleSize << 3) - 4;
    unsigned int value = 0, mod = 0xfu << moveBit; // 二进制为：1111 后面接数据类型总位数 - 4 个 0
    char *hexStr = calloc((eleSize << 1) + 1, sizeof(char));
    while (mod) {
        value = (num & mod) >> moveBit;
        if (strIndex) {
            hexStr[strIndex++] = value >= 10 ? value + 87 : value + 48;
        } else {
            if (value)
                hexStr[strIndex++] = value >= 10 ? value + 87 : value + 48;
        }
        mod >>= 4;
        moveBit -= 4;
    }
    hexStr[strIndex++] = '\0';
    hexStr = realloc(hexStr, strIndex);
    return hexStr;
}

void homework_032_405(void) {
    char *hexStr = toHex_2(-1);
    printf("the hex string is : %s\n", hexStr);
    free(hexStr);
}














