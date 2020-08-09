//
// Created by Vashon on 2020/8/5.
//

#ifndef C_HOMEWORK_007_H
#define C_HOMEWORK_007_H

#include "list_node.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

void listInsert(struct ListNode **list, int e);
void displayList(struct ListNode *list);
void destroyList(struct ListNode **list);

// 方法一：开辟新链表 + 归并法
struct ListNode *mergeTwoLists_1(struct ListNode *l1, struct ListNode *l2);

// 方法二：直接将两链归并 + 创建头节点法
struct ListNode *mergeTwoLists_2(struct ListNode *l1, struct ListNode *l2);

// 方法三：直接将两链归并 + 不创建头节点法
struct ListNode *mergeTwoLists_3(struct ListNode *l1, struct ListNode *l2);

// 方法四：递归调用
struct ListNode *mergeTwoLists_4(struct ListNode *l1, struct ListNode *l2);

void homework_007_021(void);
#endif //C_HOMEWORK_007_H
