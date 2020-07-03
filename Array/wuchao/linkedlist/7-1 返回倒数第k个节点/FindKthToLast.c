#include <stdlib.h>
//
// Created by 吴超 on 2020/7/1.
//
struct ListNode {
    int val;
    struct ListNode *next;
};

int kthToLast(struct ListNode *head, int k) {
    struct ListNode* slow = head;
    struct ListNode* fast = malloc(sizeof(struct ListNode));
    fast->val = -1;
    fast->next = head;
    int i = 0;
    while(i<k){
        fast = fast->next;
        i++;
    }
    while(fast->next!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
