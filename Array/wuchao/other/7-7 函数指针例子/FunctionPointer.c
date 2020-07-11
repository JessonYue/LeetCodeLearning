#include <stdio.h>
//
// Created by 吴超 on 2020/7/5.
//


int functionA(int a,int b);

int functionB(int c,int (*a)(int,int));

void callback(int result);

int functionC(int a,void (*callbackPointer) (int));

int functionA(int a,int b){
    return a*b;
}

int functionB(int c,int (*a)(int,int)){
    return a(c+1,c+2);
}

void callback(int result){
    printf("callback result:%d",result);
}

int functionC(int a,void (*callbackPointer) (int)){
    callbackPointer(functionB(a,functionA));
}

int main(){
    int result = functionB(4,&functionA);
    printf("functionB result:%d\n",result);
    void (*callbackPointer) (int) = &callback;
    functionC(result,callbackPointer);
}
