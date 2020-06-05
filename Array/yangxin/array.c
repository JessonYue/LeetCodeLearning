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

/**
 * 面试题 10.01. 合并排序的数组
 *
 * 给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。
 * 编写一个方法，将 B 合并入 A 并排序。初始化 A 和 B 的元素数量分别为 m 和 n。
 */
void merge(int *A, int ASize, int m, int *B, int BSize, int n) {
    int i = m - 1;
    int j = n - 1;
    int index = m + n - 1;
    //从后面向前填写，避免从前往后的移动损耗，学习别人思路
    while (i >= 0 && j >= 0 && index >= 0) {
        if (A[i] > B[j]) {
            A[index--] = A[i--];
        } else {
            A[index--] = B[j--];
        }
    }
    //如果i大于0说明a数组还没遍历完成，继续填写剩余数据
    while (i >= 0 && index >= 0) {
        A[index--] = A[i--];
    }
    //如果j大于0说明b数组还没遍历完成，继续填写剩余数据
    while (j >= 0 && index >= 0) {
        A[index--] = B[j--];
    }
}

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * 面试题 02.07. 链表相交
 *
 * 给定两个（单向）链表，判定它们是否相交并返回交点。请注意相交的定义基于节点的引用，而不是基于节点的值。
 * 换句话说，如果一个链表的第k个节点与另一个链表的第j个节点是同一节点（引用完全相同），则这两个链表相交。
 *
 * 学习网上别人的思路
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    //首先判断链表是不是为空
    if (!headA || !headB) {
        return NULL;
    }

    if (headA == headB) {
        return headA;
    }

    //获取两个链表的长度
    int lengthA = 1, lengthB = 1;
    struct ListNode *a = headA, *b = headB;


    while (a->next) {
        a = a->next;
        lengthA++;
    }
    while (b->next) {
        b = b->next;
        lengthB++;
    }
    //如果最后的值不相等说明没有相交
    if (a->val != b->val) return NULL;
    //让长的链表先走差值
    int difference = lengthA - lengthB;
    a = headA;
    b = headB;
    while (difference != 0) {
        if (difference > 0) {
            a = a->next;
            //过程中再判断是不是相交
            if (a == b) {
                return a;
            }
            difference--;
        }
        if (difference < 0) {
            b = b->next;
            //过程中再判断是不是相交
            if (a == b) {
                return a;
            }
            difference++;
        }
    }
    //找出相交的节点
    while (a && b) {
        if (a == b) {
            break;
        }
        a = a->next;
        b = b->next;
    }

    return a;
}



int main() {
    char *haystack = "mississippi";
    char *needle = "pi";

    printf("%d", strStr(haystack, needle));
    return 0;
}