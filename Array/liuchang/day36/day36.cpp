//
// Created by 刘畅 on 2020/7/6.
//

#include "day36.h"
#include<stdio.h>

int count4One(int num) {
    int tmp, count = 0;
    while (num != 0) {
        tmp = num & 1;
        if (tmp == 1)
            count++;
        num = num >> 1;
    }
    return count;
}

int main() {
    int num = 15;
    int n = count4One(num);
    printf("%d\n", n);
    return 0;
}

