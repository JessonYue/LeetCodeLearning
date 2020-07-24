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

    char hash[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};


    return hash;
}

void moveZeroes(int *nums, int numsSize) {


    for (int i = 0; i < numsSize; ++i) {
        printf("%d ", nums[i]);
    }


}


void test();

void test() {

    char *s = "abcabacdef";
    printf("firstUniqChar:%d\n", firstUniqChar(s));
//    printf("toHex(%d) = %s\n", 5, toHex(5));

    int nums[] = {0, 1, 2, 5, 0, 6, 0, 7};
    moveZeroes(nums, 8);


}


int main() {

    test();


}

