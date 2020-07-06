#include <stdio.h>
#include <stdlib.h>

/**
 * 环路检测
 */

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* detectCycle(struct ListNode* head){
    if(!head||head->next){
        return NULL;
    }
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast && fast->next){
        slow = slow->next->next;
        fast = fast->next;
        if(fast = slow){
            break;
        }
    }
    if(fast!=slow){
        return NULL;
    }
    fast = head;
    while (fast!=slow){
        fast =fast->next;
        slow = slow->next;
    }
    return fast;
}

