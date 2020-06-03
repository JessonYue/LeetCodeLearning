//
// Created by 12 on 2020/5/31.
//

#include <stdio.h>
#include <malloc.h>
#include <string.h>


/**
 * 找到数组中等于目标值的索引
 */
int findFirst(int *numbers, int target, int left, int right) {
    if (numbers == NULL || left >= right) {
        return -1;
    }

    if (numbers[left] == target) {
        return left;
    }

    if (numbers[right] == target) {
        return right;
    }

    int mid = (right + left) / 2;
    if (numbers[mid] == target) {
        return mid;
    } else if (numbers[mid] > target) {
        findFirst(numbers, target, left, mid - 1);
    } else {
        findFirst(numbers, target, mid + 1, right);
    }
}

/**
 * 167. 两数之和 II - 输入有序数组
 * 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
 * 说明:
 * 返回的下标值（index1 和 index2）不是从零开始的。
 * 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 */
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize) {
    int *arr = (int *) malloc(sizeof(int) * 2);
    int i = 0, j = numbersSize - 1;
    *returnSize = 0;
    if (numbers == NULL) {
        return arr;
    }
    while (i < j) {
        int tmp = numbers[i] + numbers[j];
        if (tmp == target) {
            arr[0] = i + 1;
            arr[1] = j + 1;
            *returnSize = 2;
            return arr;
        } else if (tmp > target) {
            j--;
        } else {
            i++;
        }
    }

    return arr;
}

int climbStairs(int n) {
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    if (n == 2) {
        return 2;
    }

    int one = 1, two = 2, r = 0;
    //斐波那契数列，递归改用循环的方式实现，参考别人代码
    for (int i = 2; i < n; i++) {
        r = one + two;
        one = two;
        two = r;
    }

    return r;
}

/**
 * 28. 实现 strStr() //https://leetcode-cn.com/problems/implement-strstr/
 * 实现 strStr() 函数。
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
 *
 * 性能不好，稍后查看学kmp算法提高效率
 */
int strStr(char *haystack, char *needle) {
    int index = -1;
    if (haystack == NULL || needle == NULL) {
        return index;
    }
//    这里跟java不同不能这么写判断是不是空串，原因不是很理解
//    if (haystack == "" || needle == "") {
//        return 0;
//    }

    int needleLength = 0;
    int haystackLength = 0;
    char cNeedle = needle[0];
    char cHaystack = haystack[0];
    //求出搜索字符串的长度
    while (cNeedle != '\0') {
        needleLength++;
        cNeedle = needle[needleLength];
    }
    //满足力扣验证规则，只有搜索字符串为空时才输出0
    if (needleLength == 0) {
        return 0;
    }

    //求出被搜索字符串的长度
    while (cHaystack != '\0') {
        haystackLength++;
        cHaystack = haystack[haystackLength];
    }

    if (haystackLength == 0) {
        return index;
    }

    for (int i = 0, isEnd = 0; i < haystackLength && isEnd != 1; i++) {
        for (int j = 0; j < needleLength; j++) {
            cNeedle = needle[j];
            if (i + j > haystackLength) {
                isEnd = 1;
                break;
            }
            cHaystack = haystack[i + j];
            if (cHaystack == cNeedle && j == (needleLength - 1)) {
                index = i;
                isEnd = 1;
                break;
            } else if (cHaystack != cNeedle) {
                break;
            }
        }
    }

    return index;
}

void MoveNext(int *next, int size) {
    for (int i = size - 1; i > 0; i--) {
        next[i] = next[i - 1];
    }
    next[0] = -1;
}

// 通过计算返回字串T的next数组
void GetNext(char *needle, int *next) {
    int pre = 0; //前缀
    int suf = 1; //后缀
    int len = strlen(needle);
    next[0] = 0;
    while (suf < len) {
        if (needle[suf] == needle[pre]) {
            pre++;
            next[suf] = pre;
            suf++;
        } else {
            if (pre > 0)
                pre = next[pre - 1];
            else {
                next[suf] = 0;
                suf++;
            }
        }
    }

    MoveNext(next, len);
}

int main() {
    char *haystack = "mississippi";
    char *needle = "pi";

    printf("%d", strStr(haystack, needle));
    return 0;
}