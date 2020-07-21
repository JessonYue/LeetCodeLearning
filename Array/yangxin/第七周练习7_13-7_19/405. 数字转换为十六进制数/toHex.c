#include <stdio.h>
#include <malloc.h>
/**
 * 405. 数字转换为十六进制数
 * 给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。
 */
char *toHex(int num) {
    char map[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    char *str = calloc(9, sizeof(char));
    int index = 7;
    int tmp;
    int count = 8;
    while (num != 0 && count > 0) {
        tmp = num & 0xf;
        str[index--] = map[tmp];
        num = num >> 4;
        count--;
    }
    if (index == 7) {
        str[index--] = '0';
    }

    return str + index + 1;
}