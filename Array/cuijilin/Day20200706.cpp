//
// Created by 崔继霖 on 2020/7/5.
//
#include <stdio.h>
#include "LinkedList.h"


/**
 * 1.计算一个数二进制中1的个数。
 *
 * */
int *getOneCount(int number);

/**
 *  * 2.将字符串反转进行输出（利用指针
 * */
void reverseCharArray(char array[]);

/**
 * 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 * https://leetcode-cn.com/problems/rotate-list/
 * */
void rotateList(LinkedList *linkedList);

/**
 * .删除链表中等于给定值 val 的所有节点
 * https://leetcode-cn.com/problems/remove-linked-list-elements/
 * */
void removeElements(LinkedList *linkedList, data value);

/**
 * 数组的相对排序https:
 * https://leetcode-cn.com/problems/relative-sort-array/
 * */
void relativeSortArray(char array[]);


void test();

int *getOneCount(int number) {

    return 0;
}

void reverseCharArray(char array[]) {
    if (array == NULL) {
        return;
    }
    int count = 0;
    while (array[count] != '\0') {
        count += 1;
    }
    for (int i = 0; i < count / 2; i++) {
        int temp = *(array + i);
        *(array + i) = *(array + (count - i - 1));
        *(array + (count - i - 1)) = temp;
    }

}

void rotateList(LinkedList *linkedList) {

}

void removeElements(LinkedList *linkedList, data value) {


}

void relativeSortArray(char array[]) {

}


void test() {
    char array[] = "abcdef";
    reverseCharArray(array);
    printf(array);
}

int main() {
    test();
}