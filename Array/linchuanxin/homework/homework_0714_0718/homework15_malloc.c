//
// Created by andylin on 2020/7/18.
//

#include <stdio.h>
#include <unistd.h>
#include <malloc.h>

int a1 = 1;
static int a2 = 11;
const int a3 = 111;

int add(int a, int b)
{
    return (a+b);
}


int main()
{
    printf("pid:%p\n", getpid());
    //printf("prd:%p\n",get)
    int b1 = 2;
    static int b2 = 22;
    const int b3 = 222;

    int* p = malloc(sizeof(int));
    printf("a1:%p\n", &a1);
    printf("a2:%p\n", &a2);
    printf("a3:%p\n", &a3);




    printf("b1:%p\n", &b1);
    printf("b2:%p\n", &b2);
    printf("b3:%p\n", &b3);
    printf("p:%p\n", p);
    printf("add:%p\n", add);
    printf("main:%p\n", main);

    while(1);
    return 0;
}