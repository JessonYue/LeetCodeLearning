//
// Created by LCX on 2020/7/30.
//
#include <stdio.h>
#include <malloc.h>

struct ListNode {
    int val;
    struct ListNode *next;
     };

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *dump = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *dumpHelper = dump;

    while (l1 != NULL && l2 != NULL){
        if(l1->val <= l2->val){
            dumpHelper->next = l1;
            l1 = l1->next;
            dumpHelper = dumpHelper->next;
        }else{
            dumpHelper->next = l2;
            l2 = l2->next;
            dumpHelper = dumpHelper->next;
        }
    }

    if(l1 == NULL)
        dumpHelper->next = l2;
    if(l2 == NULL)
        dumpHelper->next = l1;
    return dump->next;
}