//
// Created by Vashon on 2020/7/24.
//

#ifndef HOMEWORK_HOMEWORK_003_H
#define HOMEWORK_HOMEWORK_003_H

#include <string>

using namespace std;

class Homework_003 {
private:
    // 方法一：使用 C++ 自带的方法
    int strStr_1(string haystack, string needle);
    // 方法二：暴力法
    int strStr_2(string haystack, string needle);

public:
    // 实现 strStr() 函数，LeetCode第28题
    void homework_003_028();
};


#endif //HOMEWORK_HOMEWORK_003_H
