//
// Created by xiaoyaowang on 2020/7/7.
//

#include <stdio.h>

//函数指针
int (*callback)(int, int);

int add(int a, int b){
    return a + b;
}

int add2times(int a, int b){
    return (a + b) * 2;
}


//就是把函数当作参数来传递,可以想象用函数占个坑，具体函数里面怎么现实的，我们可以单独去定义，这样就很灵活了，这里的callback的具体实现可以自己去定义
int ADD(int (*callback)(int, int), int a, int b){
    return (*callback)(a, b);
}


int main(){
    //add add2times 是函数 我们都当作参数去搞
    printf("%d\n", ADD(add, 2, 3));
    printf("%d", ADD(add2times, 3, 4));
}
