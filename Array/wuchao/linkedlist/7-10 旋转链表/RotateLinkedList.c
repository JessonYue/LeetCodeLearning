//
// Created by 吴超 on 2020/7/10.
//
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *rotateRight(struct ListNode *head, int k) {
    if(head==NULL){
        return NULL;
    }
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = head;
    struct ListNode* slow = dummy;
    struct ListNode* fast = dummy;
    int length = 0;
    while(slow->next!=NULL){
        slow = slow->next;
        length++;
    }
    slow = dummy;
    k = k%length;
    while(k>0){
        fast = fast->next;
        if(fast->next==NULL){
            fast = dummy;
        }
        k--;
    }
    while(fast->next!=NULL){
        slow = slow->next;
        fast = fast->next;
    }
    if(slow==fast){
        return head;
    }
    struct ListNode* newHead = slow->next;
    slow->next = NULL;
    fast->next = head;
    return newHead;
}
