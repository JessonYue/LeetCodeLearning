//
// Created by 谢涛 on 2020/4/17.
//

#include <stdio.h>

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
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            break;
        }
    }
    if(fast != slow){
        return NULL;
    }
    fast = head;

    while(fast !=  slow){
        fast = fast->next;
        slow = slow->next;
    }
    return fast;

}
 int main(){
}
