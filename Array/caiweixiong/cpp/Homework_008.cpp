//
// Created by Vashon on 2020/8/11.
//

#include "Homework_008.h"

ListNode *Homework_008::mergeTwoLists_1(ListNode *l1, ListNode *l2) {
    if (!l1 || !l2) return l1 ? l1 : l2;
    ListNode head(0), *temp = &head;
    // 归并两条有序链
    while (l1 && l2) {
        if (l1->val < l2->val) {
            temp->next = l1;
            l1 = l1->next;
        } else {
            temp->next = l2;
             l2 = l2->next;
        }
        temp = temp->next;
    }
    // 将余下的节点全部拼接到后面，因为是有序的，所以直接拼接
    if (l1) temp->next = l1;
    if (l2) temp->next = l2;

    return head.next;
}

ListNode *Homework_008::mergeTwoLists_2(ListNode *l1, ListNode *l2) {
    if (!l1 || !l2) return l1 ? l1 : l2;
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists_2(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists_2(l1, l2->next);
        return l2;
    }
}

void Homework_008::homework_008_021() {
    ListNode *l1, *l2, *temp;
    createHeadNode(l1, 1);
    insertNode(l1, 2);
    insertNode(l1, 4);
    createHeadNode(l2, 1);
    insertNode(l2, 3);
    insertNode(l2, 4);
    displayList(l1);
    displayList(l2);
    temp = mergeTwoLists_2(l1, l2);
    displayList(temp);
    destroyList(temp);
}