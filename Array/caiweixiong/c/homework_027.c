//
// Created by Vashon on 2020/7/15.
//

#include <stdio.h>
#include "list_node.h"

// 快慢指针 + 递归
struct ListNode *rotateRight(struct ListNode *head, int k);

// 链表成环
struct ListNode *rotateRight_(struct ListNode *head, int k);

void listInsert(struct ListNode **list, int e);

void displayList(struct ListNode *list);

void destroyList(struct ListNode **list);

// 旋转链表，LeetCode第61题
void homework_027_61(void) {
    struct ListNode *list;
    listInsert(&list, 1);
    listInsert(&list, 2);
    listInsert(&list, 3);
    listInsert(&list, 4);
    listInsert(&list, 5);
    displayList(list);
//    displayList(rotateRight_(list, 3));
//    displayList(rotateRight_(list, 5));
    displayList(rotateRight_(list, 7));
    destroyList(&list);
}

struct ListNode *rotateRight(struct ListNode *head, int k) {
    if (!head || !head->next || k <= 0)
        return head;
    // 三种情况：
    // 1.移动 k 小于链表长度
    // 2.移动 k 等于链表长度
    // 3.移动 k 大于链表长度
    struct ListNode *oldHead = head, *slow = head, *quick = head;
    int length = 1, move = 0;
    while (quick->next && length <= k) {   // 计算链表长度并将指针quick移动到合适的位置
        quick = quick->next;
        length++;
    }
    if (quick->next || length > k) {   // 1.移动 k 小于链表长度
        while (quick->next) {
            quick = quick->next;
            slow = slow->next;
        }
        struct ListNode *newHead = slow->next;
        slow->next = NULL;
        quick->next = oldHead;
        return newHead;
    } else {
        move = k % length;      // 得到实际需要移动的位数
        if (k == length || !(move)) {  // 2.移动 k 等于链表长度
            return oldHead;
        } else {   // 3.移动 k 大于链表长度
            return rotateRight(oldHead, move); // 可以递归，也可以调用回第一步的操作
        }
    }
}

struct ListNode *rotateRight_(struct ListNode *head, int k) {
    if (!head || !head->next || k <= 0)
        return head;

    struct ListNode *oldTail = head, *newTail = head, *newHead = NULL;

    int length;
    for (length = 1; oldTail->next; ++length)
        oldTail = oldTail->next;
    oldTail->next = head;   // 链表成环

    for (int i = 0; i < length - k % length - 1; ++i)
        newTail = newTail->next;
    newHead = newTail->next;
    newTail->next = NULL;   // 断环
    return newHead;
}














