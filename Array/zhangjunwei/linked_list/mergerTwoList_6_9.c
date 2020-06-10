//
// Created by 张俊伟 on 2020/6/9.
//
#include <stdlib.h>

#define Data int
typedef struct ListNode_ {
    Data val;
    struct ListNode_ *next;
} ListNode;

//迭代
struct ListNode *mergeTwoLists0(ListNode *l1, ListNode *l2) {
    //先创建个节点
    ListNode *current = (ListNode *) malloc(sizeof(ListNode));
    current->val = -1;
    current->next = NULL;
    ListNode *pre = current;
    while (NULL != l1 && NULL != l2) {
        if (l1->val<l2->val){
            current->next = l1;
            l1 = l1->next;
        } else{
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    current->next = NULL!=l1 ? l1 : l2;

    return pre->next;
}
//递归
struct ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (NULL==l1)return l2;
    if (NULL==l2)return l1;

    if (l1->val<l2->val){
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else{
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}