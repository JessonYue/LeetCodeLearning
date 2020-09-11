#include "library.h"

#include <stdio.h>
#include <malloc.h>

char *toHex(int num) {
    if (num == 0) {
        return "0";
    }

    char map[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    char *str = calloc(9, sizeof(char));
    int tmp;
    int count = 7;
    while (num != 0 && count >= 0) {
        tmp = num & 0xF;
        str[count--] = map[tmp];
        num = num >> 4;
    }
    return str + count + 1;
}


int main() {

    return 0;
}