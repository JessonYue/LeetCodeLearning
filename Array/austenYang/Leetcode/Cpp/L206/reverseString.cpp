//
// Created by yangaoding on 2020/7/9.
//
#include <iostream>
#include <vector>

using namespace std;
/**
 * 向量（Vector）是一个封装了动态大小数组的顺序容器（Sequence Container）。
 * 跟任意其它类型容器一样，它能够存放各种类型的对象。
 * 可以简单的认为，向量是一个能够存放任意类型的动态数组。
 * @param s
 */

void reverseString(vector<char> &s);

int main() {
    char a[] = "hello";
    vector<char> s(a,a+5);
    reverseString(s);
    for (char i : s) {
        cout << i << "";
    }
    return 0;
}

void reverseString(vector<char> &s){
    for (unsigned int start = 0, end = s.size() -1; start < end; ++start,--end) {
        swap(s[start],s[end]);
    }
}
