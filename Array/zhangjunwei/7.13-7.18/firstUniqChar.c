//
// Created by 张俊伟 on 2020/7/14.
//
#include <stdio.h>
#include <limits.h>

int firstUniqChar1(char *s) {
    int counts[26] = {0};
    int indexs[26] = {0};
    for (int i = 0; s[i] != 0; ++i) {
        int c = s[i] - 'a';
        counts[c]++;
        if (indexs[c] == 0)
            indexs[c] = i;
    }
    int index = INT_MAX;
    for (int j = 0; j < 26; ++j) {
        if (counts[j] == 1 && indexs[j] < index) {
            index = indexs[j];
        }
    }
    return index == INT_MAX ? -1 : index;
}
int firstUniqChar(char *s) {
    //统计字母出现的次数
    int counts[26] = {0};

    for (int i = 0; s[i] != 0; ++i) {
       counts[s[i]-'a']++;
    }
    for (int i = 0; s[i] != 0; ++i) {
        if(counts[s[i]-'a']==1)
            return i;
    }
    return -1;
}