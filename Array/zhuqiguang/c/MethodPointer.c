//
// Created by qiguang.zhu on 2020/7/9.
//
#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    //����ָ��
    int (*p)(int, int) = &max;
    printf("����������\n");
    int d, e, f;
    scanf("%d %d %d", &d, &e, &f);
    printf("��������%d", p(p(d, e), f));
    return 0;
}

