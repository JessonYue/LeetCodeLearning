//
// Created by Vashon on 2020/7/15.
//

#include <stdio.h>
#include <stdlib.h>

/*
给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。

注意:
十六进制中所有字母(a-f)都必须是小写。
十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符'0'来表示；对于其他情况，十六进制字符串中的第一个字符将不会是0字符。 
给定的数确保在32位有符号整数范围内。
不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法。

示例 1：
输入: 输出:
26   "1a"

示例 2：
输入: 输出:
-1   "ffffffff"
*/

// 整数转换为十六进制数
char *toHex(int num);

// 获取数值对应的ascii码表的十六进制字符的值
char getHexChar(int value);

// 数字转换为十六进制数，LeetCode第405题
void homework_032_405(void) {
    char *hexStr = toHex(935);
    printf("the hex string is : %s\n", hexStr);
    free(hexStr);
}

char *toHex(int num) {
    if (num == 0)
        return "0\0";
    // 一个十六进制数由 4 位二级制数组成，而一个字节有 8 位，所以最大需要开辟的空间就是数据类型字节数的两倍
    const int length = 2 * sizeof(int);
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
            return 48;
        case 1:
            return 49;
        case 2:
            return 50;
        case 3:
            return 51;
        case 4:
            return 52;
        case 5:
            return 53;
        case 6:
            return 54;
        case 7:
            return 55;
        case 8:
            return 56;
        case 9:
            return 57;
        case 10:
            return 97;
        case 11:
            return 98;
        case 12:
            return 99;
        case 13:
            return 100;
        case 14:
            return 101;
        case 15:
            return 102;
        default:
            return 0;
    }
}














