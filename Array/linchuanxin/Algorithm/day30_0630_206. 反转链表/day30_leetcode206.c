day30_leetcode_206//
// Created by LCX on 2020/7/1.
//
#include <stdio.h>


struct ListNode {
    int val;
    struct ListNode *next;
};



struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *pre = NULL;
    struct ListNode *cur = head;

    while (cur != NULL)
    {
        struct ListNode *tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }

    return pre;
}