//
// Created by Vashon on 2020/7/24.
//

#include <iostream>
#include "Homework_003.h"

int Homework_003::strStr_1(string haystack, string needle) {
    return needle.empty() ? 0 : haystack.find(needle);
}

int Homework_003::strStr_2(string haystack, string needle) {
    if (needle.empty())
        return 0;
    int bigSize = haystack.size(), tinySize = needle.size();
    if (bigSize < tinySize)
        return -1;
    const char *bigStr = haystack.data(), *tinyStr = needle.data();
    int bigStart = 0;
    int loopCount = bigSize - tinySize + 1;
    while (bigStart < loopCount) {
        // 过滤前面不匹配的字符
        while (bigStart < loopCount && bigStr[bigStart] != tinyStr[0]) ++bigStart;
        // 计算最大能匹配到的字符串
        int matchSize = 0;
        while (matchSize < tinySize && bigStart < bigSize && bigStr[bigStart] == tinyStr[matchSize])
            matchSize++, bigStart++;
        if (matchSize == tinySize)  // 匹配成功
            return bigStart - tinySize;
        // 匹配不成功，将原大串开始匹配的字符位置后移一位
        bigStart = bigStart - matchSize + 1;
    }

    return -1;
}

void Homework_003::homework_003_028() {
    string haystack = "hello", needle = "ll";
    cout << "字符串 haystack ：" << haystack << endl;
    cout << "字符串 needle ：" << needle << endl;
    int resultCode = strStr_2(haystack, needle);
    if (resultCode == -1)
        cout << "字符串 haystack 中不存在子字符串 needle" << endl;
    else
        cout << "字符串 haystack 中子字符串 needle 所在位置的索引为：" << resultCode << endl;
}