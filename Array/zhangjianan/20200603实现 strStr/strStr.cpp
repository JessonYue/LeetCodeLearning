//
// Created by 张佳男 on 2020/6/3.
//

#include <iostream>
#include <cstring>

int strStr(char *haystack, char *needle) {
    int haystackLength = strlen(haystack);
    int needleLength = strlen(needle);
    if ( needleLength == 0) {
        return 0;
    }
    for (int i = 0; i < haystackLength; ++i) {
        if (haystack[i] == needle[0]) {
            if (needleLength==1) {
                return i;
            }
            for (int j = 1; j <needleLength; ++j) {
                if (haystack[i+j]!=needle[j]) {
                    break;
                }
                if (j == needleLength - 1) {
                    return i;
                }
            }
        }
    }
    return -1;
}

int main() {
    std::cout << strStr("abcabcabcd","cd") << std::endl;
    return 0;
}