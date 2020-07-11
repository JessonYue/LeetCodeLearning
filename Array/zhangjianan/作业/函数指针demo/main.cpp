#include <iostream>
#include "FIFO.cpp"

void callBack(int result);
void functionA(int a, void (*callBackPointer)(int));

void callBack(int result){
    printf("callback result:%d",result);
}
void functionA(int a, void (*callBackPointer)(int)) {
    callBackPointer(a);
}
int main() {
    void (*callBackPointer)(int)=&callBack;
    functionA(123, callBackPointer);
    functionA(456,&callBack);
    functionA(789,callBack);
    return 0;
}
