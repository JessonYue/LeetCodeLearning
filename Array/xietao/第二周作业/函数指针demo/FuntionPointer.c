//
// Created by 谢涛 on 2020/7/7.
//
#include <stdio.h>
#include <stdlib.h>

int max(int x, int y){
    return x > y ? x : y;
}

//获取随机值
int getNextRand(void ){
    return rand();
}

//回调函数
void populate(int *array, size_t size, int (*getNextRand)(void)){
    for (int i = 0; i < size; ++i) {
        array[i] = getNextRand();
    }
}



int main(){

    int array[10];
    populate(array, 10, getNextRand);
    for (int i = 0; i < 10; ++i) {
        printf("%d\n", array[i]);
    }

//    int (*p)(int, int ) = max;
//    int a = 1, b = 2, c = 3;
//    int d;
//    d = p(p(a,b),c);
//    printf("最大数:%d",d);
    return 1;
}
