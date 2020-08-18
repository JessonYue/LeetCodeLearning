//
// Created by 崔继霖 on 2020/7/14.
//

#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

/**
 * 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
 * */
int firstUniqChar(char *s);

/**
 * https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal/
 * 给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。
 * */
char *toHex(int num);

// 滑动窗口
char *toHex2(int num);

/**
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * */
void moveZeroes(int *nums, int numsSize);

int firstUniqChar(char *s) {
    int hash[26] = {0};
    int length = strlen(s);
    for (int i = 0; i < length; i++) {
        hash[s[i] - 'a']++;
    }
    for (int i = 0; i < length; i++) {
        if (hash[s[i] - 'a'] == 1) {
            return i;
        }
    }
    return -1;
}

char *toHex(int num) {

    char table[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    char *res = (char *) calloc(9, sizeof(char));
    // 最长 8 位！
    int idx = 7, cnt = 8;
    // 倒置填充索引与计数器
    do {
        int lowbit4 = num & 0xf;
        res[idx--] = table[lowbit4];
        num >>= 4;
        cnt -= 1;
        printf("res = %s\n",res);
        printf("low = %c\n",table[lowbit4]);
    } while (num != 0 && cnt > 0);
    // TODO  wtf ???
    return res + idx + 1;  // 地址截取
}

char *toHex2(int num) {

    char table[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    // 最长 8 位 ！
    char *res = (char *) calloc(9, sizeof(char));
    res[0] = '0';
    int move = 28;
    int index = 0;
    unsigned int highbit4 = 0xf0000000;

    while (highbit4 != 0) {
        int result = (num & highbit4) >> move;
        if (result != 0 || res[0] != '0') {
            res[index++] = table[result];
        }
        move -= 4;
        highbit4 >>= 4;
    }

    return res;  // 地址截取
}

void moveZeroes(int *nums, int numsSize) {
    for (int i = 0; i < numsSize; ++i) {
        printf("%d ", nums[i]);
    }
}


void test();

void test() {

    char *s = "abcabacdef";
//    printf("firstUniqChar:%d\n", firstUniqChar(s));

    printf("toHex(%p) = %s\n", 255, toHex(255));

//    int nums[] = {0, 1, 2, 5, 0, 6, 0, 7};
//    moveZeroes(nums, 8);


}


int main() {

    test();

}

