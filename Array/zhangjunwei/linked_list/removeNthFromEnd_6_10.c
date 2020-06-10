//
// Created by 张俊伟 on 2020/6/10.
//
#include <stdlib.h>

#define Data int
typedef struct ListNode_ {
    Data val;
    struct ListNode_ *next;
} ListNode;

ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dumpNode = (ListNode *) malloc(sizeof(ListNode));
    dumpNode->next = head;
    ListNode *p = dumpNode;
    ListNode *q = dumpNode;
    int i = 1;
    n+=1;
    while (i<=n){
        p = p->next;
        i++;
    }
    while (p!=NULL){
        p = p->next;
        q = q->next;
    }
    q->next = q->next->next;
    return dumpNode->next;
}