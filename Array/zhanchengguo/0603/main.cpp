#include <iostream>
#include <iostream>
#include "string"

using namespace std;

int strStr1(string haystack, string needle);

int strStr2(string haystack, string needle);

int main() {
    int value1 = strStr1("hello", "ll");
    int value2 = strStr2("hello", "ll");
    printf("value is %d, %d\n", value1, value2);
    return 0;
}

/**
 * 这种方法使用两层循环遍历去判断字符串是否的每个字符是否相等，
 * 在数据量过大的情况下，会导致耗时过长
 * @param haystack
 * @param needle
 * @return
 */
int strStr1(string haystack, string needle) {
    if (needle.empty()) {
        return 0;
    }
    if (haystack.size() < needle.size()) {
        return -1;
    }
    for (int i = 0; i < haystack.size(); i++) {
        if (haystack[i] == needle[0]) {
            bool end = true;
            for (int j = 1; j < needle.size(); j++) {
                if (haystack[i + j] != needle[j]) {
                    end = false;
                    break;
                }
            }
            if (end) {
                return i;
            }
        }
    }
    return -1;
}

/**
 * 该方法在上述方法的基础上，缩减了一层循环判断，当第一个字符相等时，则一个个对比下去，出现一个不想等的
 * 主字符则从之前刚刚开始判断的字符位置的下一位重新开始判断，是否和目标字符的首字符相等，减少了耗时
 * @param haystack
 * @param needle
 * @return
 */
int strStr2(string haystack, string needle) {
    if (needle.empty()) {
        return 0;
    }
    if (haystack.size() < needle.size()) {
        return -1;
    }
    int i = 0;
    int j = 0;
    for (i = 0; i < haystack.size(); i++) {
        if (j == needle.size()) {
            return i - needle.size();
        }
        if (haystack[i] == needle[j]) {
            j++;
        } else {
            i -= j;
            j = 0;
        }
    }
    if (j == needle.size()) {
        return i - needle.size();
    }
    return -1;
}
