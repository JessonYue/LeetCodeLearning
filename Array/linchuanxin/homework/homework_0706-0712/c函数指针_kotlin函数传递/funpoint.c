//
// Created by LCX on 2020/7/9.
//
#include <stdio.h>

int Max(int, int);
int Max(int a, int b)
{
    printf("%d___%d\n",a,b);
    int j;
    if(a > b)
        j = a;
    else
        j = b;
    return j;
}


int main(void)
{
    printf("%p\n",Max);
    int (*p)(int,int);
    int a,b,c;
    printf("%p\n",p);
    p = Max;
    printf("%p\n",p);
    a = 3;
    b = 4;
    c = (*p)(a,b);
    printf("a=%d\nb=%d\nmax=%d\n",a,b,c);

    return 0;
}
