#include <iostream>

using namespace std;

/**
 * 在程序中定义了一个函数，那么在编译时系统就会为这个函数代码分配一段存储空间，
 * 这段存储空间的首地址称为这个函数的地址，而且函数名表示的就是这个地址
 * 既然是地址我们就可以定义一个指针变量来存放，这个指针变量就叫作函数指针变量，简称函数指针。
 *
 * 格式：函数返回值类型 (* 指针变量名) (函数参数列表); 例子：int(*p)(int, int);
 * 说明：定义了一个指针变量 p，该指针变量可以指向返回值类型为 int 型，且有两个整型参数的函数
 *
 */

int add1(int a, int b);

int add2(int a, int b);

void addImpl(int aa, int bb, int (*p)(int a, int b));

int main() {
    int a = 5;
    int b = 10;
    addImpl(a, b, add1);
    addImpl(a, b, add2);
    return 0;
}

int add1(int a, int b) {
    return a + b + 5;
}

int add2(int a, int b) {
    return a + b + 10;
}

void addImpl(int aa, int bb, int (*p)(int a, int b)) {
    printf("result is %d\n", (*p)(aa, bb));
}