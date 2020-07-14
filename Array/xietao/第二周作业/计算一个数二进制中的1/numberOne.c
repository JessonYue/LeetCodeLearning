//
// Created by 谢涛 on 2020/7/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int number(unsigned int num){
    int tem,count = 0;
    while (num != 0){
        tem = num & 1;
        if (tem == 1){
            count++;
        }
        num = num >> 1;
    }
    return count;

}

int main() {
    printf("111111111");
    int aaa = number(14);

    printf("aaa=%d \n",aaa);

    return 0;
}
