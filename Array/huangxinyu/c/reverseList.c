//
// Created by hasee on 2020/6/9.
//
#include "alo.h"

ListNode *reverseList(ListNode *head, int i) {
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

ListNode *reverseList1(ListNode *head, int i) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode *pNode = reverseList(head->next, i);
    head->next->next = head;
    head->next = NULL;
    return pNode;

}
