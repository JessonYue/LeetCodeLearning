//
// Created by Vashon on 2020/7/15.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>


/*
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
s = "leetcode"
返回 0

s = "loveleetcode"
返回 2
*/

// 方法一：每个字符逐个对比
int firstUniqChar(char *s);

// 方法二：散列表思想，将时间复杂度从n^2变成n
int firstUniqChar_(char *s);

// 字符串中的第一个唯一字符，LeetCode第387题
void homework_031_387(void) {
    char *s1 = "leetcode";
    char *s2 = "loveleetcode";
    printf("first index : %d\n", firstUniqChar_(s1));
    printf("first index : %d\n", firstUniqChar_(s2));
}

int firstUniqChar(char *s) {
    if (!s)
        return -1;
    unsigned long long len = strlen(s);
    if (len == 0)
        return -1;
    char *pre = s;
    int index = 0;
    for (int i = 0; i < len; ++i) { // 两次循环进行比较
        bool exited = false;
        index = i;
        for (int j = 0; j < len; ++j) {
            if (i == j)
                continue;
            if (pre[i] == pre[j]) {
                exited = true;
                index = -1;
                break;
            }
        }
        if (!exited)
            break;
    }
    return index;
}

int firstUniqChar_(char *s) {
    if (!s)
        return -1;
    unsigned long long len = strlen(s);
    if (len == 0)
        return -1;
    int words[26] = {0};
    for (int i = 0; i < len; ++i)   // 将每个字符出现的次数累计在一个数组内
        words[s[i] - 'a']++;
    for (int j = 0; j < len; ++j) {
        if (words[s[j] - 'a'] == 1) // 当字符累计数为 1，则满足条件
            return j;
    }
    return -1;
}













