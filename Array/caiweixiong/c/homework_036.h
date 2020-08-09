//
// Created by Vashon on 2020/8/3.
//

#ifndef C_HOMEWORK_036_H
#define C_HOMEWORK_036_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "list_node.h"

void listInsert(struct ListNode **list, int e);

void displayList(struct ListNode *list);

void destroyList(struct ListNode **list);

// 方法一：递归 + 归并
struct ListNode *sortList_1(struct ListNode *head);

// 方法二：迭代 + 归并
int getLinkSize(struct ListNode *head);

// 找到需要归并的第二条链的链头并计算链中的节点个数，最终返回余下部分链的节点
struct ListNode *findLinkHeadAndComputeSize(
        struct ListNode *head, struct ListNode **linkHead,
        int mergeSize, int *restSize, int *size2, bool *isBreak);

// 归并链表
struct ListNode *mergeAndSortLink(
        struct ListNode *head, struct ListNode *link1,
        struct ListNode *link2, struct ListNode *restLink,
        int size1, int size2);

struct ListNode *sortList_2(struct ListNode *head);

// 排序链表，LeetCode第148题
void homework_036_148(void);

#endif //C_HOMEWORK_036_H
