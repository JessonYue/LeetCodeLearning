//
// Created by Jesson on 2020/7/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

using namespace std;

void GetMemoryInfo( int *p )
{
    p = (int *) malloc( 100 );
    //cout<<p<<endl;
}

void GetMemoryInfo( int **p )
{
    *p = (int *) malloc( 100 ); //操作*p也就是操作str。
    cout<<*p<<endl;
    memcpy(*p,"abcdefg",7);
}


int main()
{
    int *str = NULL;
    GetMemoryInfo(str);
    //cout<<str;

    int **p2=&str; //等价于int **p2; p2=&str;
    GetMemoryInfo(p2);
    cout<<str<<endl;
    printf("%c",((char*)str)[1]); //注意这个里的写法
    return 0;
}
