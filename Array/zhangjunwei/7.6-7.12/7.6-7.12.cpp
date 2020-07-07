//
// Created by 张俊伟 on 2020/7/6.
//
#include <iostream>
#include <cstdlib>
#include <cstring>

//1.计算一个数二进制中1的个数。
int cal_binary_num(long int num) {
    int count{};
    if (num < 0) {//有符号数  取反加1
        num = ~num + 1;
    }
    while (num) {
        if (num & 1)
            count++;
        num >>= 1;
    }
    return count;
}

//2.将字符串反转进行输出（利用指针）。
char *rever_character(char const *str, int n) {
    char *p = const_cast<char *>(str);
    char *rever = (char *) malloc(sizeof(char) * n);
    if (rever == nullptr)return nullptr;
    for (int i = 0; i < n; ++i) {
        *(rever + i) = *(p + n - i - 1);
    }
    return rever;
}

typedef void (*call_back)(int);

void printf_call(int num) {
    std::cout << num << std::endl;
}

void for_each(int *arr, int n, call_back call) {
    if (call != nullptr) {
        for (int i = 0; i < n; ++i) {
            call(*(arr + i));
        }
    }
}

int main() {
//    std::cout << cal_binary_num(0xf1f1) << std::endl;
//    const char *str = {"abcabc"};
//    std::cout << rever_character(str, strlen(str)) << std::endl;
    int arr[] = {2,3,4,6,6,10,0};
    for_each(arr,7, printf_call);
    return 0;
}