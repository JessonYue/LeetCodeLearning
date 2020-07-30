//
// Created by LCX on 2020/7/29.
//
#include <stdio.h>
#include <malloc.h>

struct ListNode {
         int val;
    struct ListNode *next;
};

struct ListNode* cut(struct ListNode* head,int n){
    if(n<=0)
        return head;
    struct ListNode *p = head;
    while (--n > 0 && p != NULL)
        p = p->next;
    if (p == NULL)
        return NULL;
    struct ListNode *next = p->next;
    p->next = NULL;
    return next;
}


struct ListNode* merge(struct ListNode* list1,struct ListNode* list2){
    struct ListNode *dummyNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p = dummyNode;
    while (list1!=NULL && list2!=NULL)
    {
        if (list1->val<list2->val)
        {
            p->next = list1;
            list1 = list1->next;
        }else
        {
            p->next = list2;
            list2 = list2->next;
        }
        p = p->next;
    }
    if(list1 == NULL)
        p->next = list2;
    else
        p->next = list1;

    return dummyNode->next;
}


struct ListNode* sortList(struct ListNode* head){
    struct ListNode *dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    struct ListNode *p = dummyHead->next;
    int length = 0;
    while (p!=NULL)
    {
        ++length;
        p = p->next;
    }

    for (int size = 1; size < length; size <<=1) {
        struct ListNode *cur = dummyHead->next;
        struct ListNode *tail = dummyHead;
        while (cur!=NULL)
        {
            struct ListNode *left = cur;
            struct ListNode *right = cut(cur,size);
            cur = cut(right,size);
            tail->next = merge(left,right);
            while (tail->next!=NULL)
                tail = tail->next;
        }
    }
    return dummyHead->next;
}

