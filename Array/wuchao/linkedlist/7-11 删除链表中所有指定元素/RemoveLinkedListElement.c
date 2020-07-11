//
// Created by 吴超 on 2020/7/11.
//
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *removeElements(struct ListNode *head, int val) {
    struct ListNode* prev = malloc(sizeof(struct ListNode));
    prev->val = -1;
    prev->next = head;
    struct ListNode* current = head;
    struct ListNode* newHead = head;
    while(current!=NULL){
        if(current->val == val){
            if(current == newHead){
                newHead = newHead->next;
            }
            prev->next = current->next;

        }else{
            prev = prev->next;
        }
        current = current->next;
    }
    return newHead;
}
