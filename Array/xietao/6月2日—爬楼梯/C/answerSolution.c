//
// Created by 谢涛 on 2020/6/3.
//

#include <stdio.h>
int child(int statr, int end);

int main() {
    printf("Hello, World!\n");
    int number = child(0,5);
    printf("number=%d\n",number);
    return 0;
}


int child(int statr, int end){
    if(statr > end){
        return 0;
    }
    if(statr == end){
        return 1;
    }

    return child(statr + 1 , end) + child(statr + 2, end);
}
