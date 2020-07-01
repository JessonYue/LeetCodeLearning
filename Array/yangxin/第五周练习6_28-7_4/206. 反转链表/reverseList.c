#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL) {
        return NULL;
    }
    struct ListNode* newHead = NULL;
    struct ListNode* next = head;
    struct ListNode* tmp = NULL;
    while(next != NULL) {
        tmp = next->next;
        next->next = newHead;
        newHead = next;
        next = tmp;
    }
    return newHead;
}