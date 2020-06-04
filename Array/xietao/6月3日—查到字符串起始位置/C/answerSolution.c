//
// Created by 谢涛 on 2020/6/3.
//

#include <stdio.h>
#include <stdlib.h>

int strStr(char * haystack, char * needle);
int main() {
    char *haystack = "hwwwello";
    char *needle = "ll";
    int index = strStr(haystack,needle);
    printf("index=%d\n",index);
    return 0;
}

int strStr(char * haystack, char * needle){
    int L = strlen(needle);
    int n = strlen(haystack);
    if(L ==0) return 0;
    int pn = 0;
    while(pn < n - L +1){
        while(pn < n - L + 1 && haystack[pn] != needle[0]) ++pn;
        int currLen = 0, pL = 0;
        while(pL < L && pn < n && haystack[pn] == needle[pL]){
            ++pn;
            ++pL;
            ++currLen;
        }
        if(currLen == L){
            return pn - L;
        }
        pn = pn -currLen +1;
    }
    return -1;
}





