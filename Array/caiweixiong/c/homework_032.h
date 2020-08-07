//
// Created by Vashon on 2020/8/6.
//

#ifndef C_HOMEWORK_032_H
#define C_HOMEWORK_032_H

#include <stdio.h>
#include <stdlib.h>

/*
给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。

注意:
十六进制中所有字母(a-f)都必须是小写。
十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符'0'来表示；对于其他情况，十六进制字符串中的第一个字符将不会是0字符。 
给定的数确保在32位有符号整数范围内。
不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法。

示例 1：
输入: 输出:
26   "1a"

示例 2：
输入: 输出:
-1   "ffffffff"
*/

// 方法一：倒叙法，从十六进制数的低位开始转换
char *toHex_1(int num);

// 获取数值对应的ascii码表的十六进制字符的值
char getHexChar(int value);

// 方法二：顺序法，从十六进制数的高位开始转换
char *toHex_2(int num);

// 数字转换为十六进制数，LeetCode第405题
void homework_032_405(void);

#endif //C_HOMEWORK_032_H
