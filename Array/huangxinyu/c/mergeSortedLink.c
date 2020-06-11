//
// Created by hasee on 2020/6/10.
//
#include "alo.h"

/**
 * 两种思路，一种新建一个链表，将结果放到新链表中，另一种直接放到原来的其中一个链表中。
 * 以下使用第二种方式
 */
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1 || !l2) return l1;
    ListNode *preHead = malloc(sizeof(ListNode));
    ListNode *pre = preHead;
    while (!l1 && !l2) {
        if (l1->val < l2->val) {
            pre->next = l1;
            l1 = l1->next;
        } else {
            pre->next = l2;
            l2 = l2->next;
        }
        pre = pre->next;
    }
    pre->next = l1 == NULL ? l2 : l1;
    return preHead->next;
}