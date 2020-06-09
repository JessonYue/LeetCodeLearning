//
// Created by 谢涛 on 2020/6/3.
//

#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *newNode = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *preve = newNode;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            preve->next = l1;
            l1 = l1->next;
        } else {
            preve->next = l2;
            l2 = l2->next;
        }
        preve = preve->next;
    }

    preve->next = l1 == NULL ? l2 : l1;

    return newNode->next;
}






