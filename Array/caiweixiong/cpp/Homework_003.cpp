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
        // ����ǰ�治ƥ����ַ�
        while (bigStart < loopCount && bigStr[bigStart] != tinyStr[0]) ++bigStart;
        // ���������ƥ�䵽���ַ���
        int matchSize = 0;
        while (matchSize < tinySize && bigStart < bigSize && bigStr[bigStart] == tinyStr[matchSize])
            matchSize++, bigStart++;
        if (matchSize == tinySize)  // ƥ��ɹ�
            return bigStart - tinySize;
        // ƥ�䲻�ɹ�����ԭ�󴮿�ʼƥ����ַ�λ�ú���һλ
        bigStart = bigStart - matchSize + 1;
    }

    return -1;
}

void Homework_003::homework_003_028() {
    string haystack = "hello", needle = "ll";
    cout << "�ַ��� haystack ��" << haystack << endl;
    cout << "�ַ��� needle ��" << needle << endl;
    int resultCode = strStr_2(haystack, needle);
    if (resultCode == -1)
        cout << "�ַ��� haystack �в��������ַ��� needle" << endl;
    else
        cout << "�ַ��� haystack �����ַ��� needle ����λ�õ�����Ϊ��" << resultCode << endl;
}