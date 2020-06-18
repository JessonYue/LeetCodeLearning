//
// Created by 谢涛 on 2020/6/3.
//

#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


 int isPalindrome(struct ListNode* head){
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* pre = NULL;
    while(fast != NULL && fast->next != NULL){
        struct ListNode* cur = slow;
        slow = slow->next;
        fast = fast->next->next;
        cur->next = pre;
        pre = cur;
    }
    if(fast != NULL) slow = slow->next;
    while(pre != NULL){
        if(pre->val != slow->val){
            return 0;
        }
        pre = pre->next;
        slow = slow->next;
    }
    return 1;
}






