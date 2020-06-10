//
// Created by hasee on 2020/6/9.
//
#include "alo.h"

ListNode *reverseList(ListNode *head) {
    ListNode *pre = NULL;
    ListNode *cur = head;
    while (cur) {
        ListNode *temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}