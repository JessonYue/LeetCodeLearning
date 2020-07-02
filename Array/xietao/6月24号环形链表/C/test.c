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
bool hasCycle(struct ListNode *head) {
    if(NULL == head || NULL == head->next)
        return false;
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;

    while(slow != fast){
        if(NULL == head || NULL == head->next)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}
 int main(){
}
