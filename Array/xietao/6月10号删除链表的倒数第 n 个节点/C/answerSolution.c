//
// Created by 谢涛 on 2020/6/3.
//

#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->next = head;
    struct ListNode* p = newNode;
    struct ListNode* q = newNode;
    while(n >= 0){
        n--;
        p = p->next;
    }
    while(p != NULL){
        p = p->next;
        q = q->next;
    }
    q->next = q->next->next;

    return newNode->next;






