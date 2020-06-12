//
// Created by hasee on 2020/6/12.
//
#include "alo.h"
ListNode* oddEvenList(ListNode* head){
    if (head == nullptr) return nullptr;
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = even;
    while (even != nullptr && even->next != nullptr) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}