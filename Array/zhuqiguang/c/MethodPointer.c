//
// Created by qiguang.zhu on 2020/7/9.
//
#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    //函数指针
    int (*p)(int, int) = &max;
    printf("请输入数字\n");
    int d, e, f;
    scanf("%d %d %d", &d, &e, &f);
    printf("最大的数字%d", p(p(d, e), f));
    return 0;
}

