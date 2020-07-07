//
// Created by xiaoyaowang on 2020/7/7.
//
#include <stdio.h>
#include <string.h>

void exchange(char* arr) {

    int length;
    char *p1;
    char *p2;

    length = strlen(arr);        //获取字符串长度
    p1 = arr;                //p1指向字符串首地址
    p2 = arr + length - 1;    //p2指向字符串尾地址
    if (arr == NULL) {
        printf("空指针错误！");
        return;
    }
    while (p1 < p2)                //当p1地址小于p2地址时执行循环
    {
        char c = *p1;
        *p1 = *p2;                //完成指针指向地址的值的交换 *p1是p1里面存放的值，也就是交换了值，地址没有变
        *p2 = c;
        p1++; //指向下一个地址
        p2--; //指向上一个地址
    }
}

int main(){
    char arr[] = "123456";
    exchange(arr);
    printf("%s", arr);
}
