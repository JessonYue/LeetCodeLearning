//
// Created by Vashon on 2020/7/15.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*
给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。

注意：如果对空文本输入退格字符，文本继续为空。

示例 1：
输入：S = "ab#c", T = "ad#c"
输出：true
解释：S 和 T 都会变成 “ac”。

示例 2：
输入：S = "ab##", T = "c#d#"
输出：true
解释：S 和 T 都会变成 “”。

示例 4：
输入：S = "a#c", T = "b"
输出：false
解释：S 会变成 “c”，但 T 仍然是 “b”。
*/

// 方法一：用栈的思想，很容易就可以做出来了
bool backspaceCompare(char *S, char *T);
// 方法二：双指针法，时间复杂度不变，空间复杂度变O(1)
bool backspaceCompare_(char *S, char *T);

// 比较含退格的字符串，LeetCode第844题
void homework_034_844(void) {
    char *S = "a#c";
    char *T = "b";
    if (backspaceCompare(S, T))
        printf("compare is true\n");
    else
        printf("compare is fail\n");
}

bool backspaceCompare(char *S, char *T) {
    if ((!S && !T) || (*S == '\0' && *T == '\0'))
        return true;
    char s[200] = {'\0'}, t[200] = {'\0'}, *sp = S, *tp = T;
    int stop = -1, ttop = -1;   // 栈顶指针
    // 分别将字符串 S、T 进行退格处理
    while (*sp != '\0') {
        if (*sp != '#')
            s[++stop] = *sp++;
        else {
            if (stop != -1)
                s[stop--] = '\0';
            sp++;
        }
    }
    while (*tp != '\0') {
        if (*tp != '#')
            t[++ttop] = *tp++;
        else {
            if (ttop != -1)
                t[ttop--] = '\0';
            tp++;
        }
    }
    if (stop != ttop)   // 栈顶指针位置都不同，证明退格后元素不同
        return false;
    for (int i = 0; i <= stop; ++i) {
        if (s[i] != t[i])
            return false;
    }
    return true;
}

bool backspaceCompare_(char *S, char *T) {
    if ((!S && !T) || (*S == '\0' && *T == '\0'))
        return true;
    int sidx = strlen(S) - 1, tidx = strlen(T) - 1; // 得到连个字符串最后一个字符的索引
    int sskip = 0, tskip = 0;   // 统计退格后需要跳过的字符数
    while (sidx >= 0 || tidx >= 0) {
        while (sidx >= 0) {      // 处理字符串 S
            if (S[sidx] == '#')  // 统计退格符号
                sskip++, sidx--;
            else if (sskip)      // 存在退格符号，将对应数量的字符忽略
                sskip--, sidx--;
            else
                break;
        }
        while (tidx >= 0) {
            if (T[tidx] == '#')
                tskip++, tidx--;
            else if (tskip)
                tskip--, tidx--;
            else
                break;
        }
        if (sidx >= 0 && tidx >= 0 && S[sidx] != T[tidx])   // 当前的字符不匹配
            return false;
        // 这里需要注意，不能仅判断索引不等因为有可能在遇到退格符前，索引是不等的，
        // 而且需保证两者所以同时大于零，有可能遇到退格时，有一个字符串直接就退格完了，这时索引为 -1，只要没退格完，索引最小也为 0
        if ((sidx >= 0) != (tidx >= 0))
            return false;
        sidx--, tidx--;
    }
    return true;
}











