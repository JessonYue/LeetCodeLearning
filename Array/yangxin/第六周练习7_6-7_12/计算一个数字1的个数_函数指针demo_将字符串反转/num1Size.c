//
// Created by 12 on 2020/7/6.
//
#include <stdio.h>
#include <string.h>
#include <malloc.h>

//计算一个数二进制中1的个数,参考网上资料实现，原理不是很明白
int num1Size(int num) {
    int count = 0;
    while (num) {
        num &= num - 1;
        count++;
    }
    return count;
}

//将字符串反转进行输出（利用指针）
void reversalStr(char *str) {

    int size = strlen(str);
    char *s = calloc(size, sizeof(char));
    int i = 0;
    while (str[i] != 0) {
        s[i] = str[i];
        i++;
    }
    int left = 0;
    int right = size - 1;
    while (left < right) {
        char c = s[left];
        s[left] = s[right];
        s[right] = c;
        left++;
        right--;
    }

    printf("%s\n", s);
}

//函数指针demo
int (*fun)(int, int);
int add(int a, int b) {
    return a+b;
}



void main() {
    printf("%d\n", num1Size(9));
    reversalStr("hello world!");

    fun = add;
    printf("%d\n", fun(1,2));
}