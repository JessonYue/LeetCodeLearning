//
// Created by 谢涛 on 2020/6/30.
//
#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(!head || !head->next){
        return NULL;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }
    if(slow != fast){
        return NULL;
    }
    fast = head;
    while(fast != slow){
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}
int main() {

    return 0;
}