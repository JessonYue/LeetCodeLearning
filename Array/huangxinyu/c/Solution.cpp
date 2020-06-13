//
// Created by hasee on 2020/6/13.
//
#include "alo.h"

bool isPalindrome(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *pre = head;
    ListNode *prepre = nullptr;
    while (fast != nullptr && !fast->next) {
        pre = slow;
        fast = fast->next->next;
        slow = slow->next;
        pre->next = prepre;
        prepre = pre;
    }
    if (!fast) {
        slow = slow->next;
    }
    while (slow != nullptr) {
        if (pre->val != slow->val) {
            return false;
        }
        pre = pre->next;
        slow = slow->next;
    }
    return true;
}
