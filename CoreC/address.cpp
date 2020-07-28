//
// Created by Jesson on 2020/7/18.
//
#include <iostream>

using namespace std;

int main()
{
    int *str= NULL;
    int **p=NULL;
    p=&str;

//    int* a;
//    *a = 100;
    cout<<str<<endl; //没有数据 str的值就是NULL的地址（NULL的地址被宏定义为0）这个和编译器有关系
//    cout<<*str<<endl; //崩溃
    cout<<&str<<endl; //取地址
    cout<<p<<endl;

    //对P的修改也就是对str的修改？
}