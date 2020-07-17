//
// Created by Vashon on 2020/7/9.
//

#include <stdio.h>

void testSum(int a, int b);
void testSub(int a, int b);
void testDef(void);
void testFunPointer(void (*f)(), int);

// 测试函数指针
void homework_fun_pointer(void) {
    void (*fun)() = testSum;    // 定义一个函数指针，将 testSum 函数的地址赋值给它
    testFunPointer(fun, 1);
    fun = testSub;
    testFunPointer(fun, 2);
    fun = testDef;
    testFunPointer(fun, 3);
}

void testSum(int a, int b) {
    printf("add result : %d\n", a + b);
}

void testSub(int a, int b) {
    printf("sub result : %d\n", a - b);
}

void testDef(void) {
    printf("can not find fun\n");
}

void testFunPointer(void (*f)(), int type) {
    switch (type) {
        case 1:
            f(3, 4);
            break;
        case 2:
            f(5, 4);
            break;
        default:
            f();
    }
}