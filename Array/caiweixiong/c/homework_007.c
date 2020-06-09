//
// Created by Vashon on 2020/6/9.
//

#include "list_node.h"
#include <stdio.h>
#include <stdlib.h>

void listInsert(struct ListNode **list, int e);

// 合并两个有序链表，LeetCode第21题
void homework_007_021(void) {
    struct ListNode *list1 = NULL, *list2 = NULL, *list = NULL;
    void displayList(struct ListNode *list);
    void destroyList(struct ListNode **list);
    struct ListNode *mergeTwoLists(struct ListNode *, struct ListNode *);
    listInsert(&list1, 1);
    listInsert(&list1, 2);
    listInsert(&list1, 4);
    listInsert(&list2, 1);
    listInsert(&list2, 3);
    listInsert(&list2, 4);
    printf("链表1的元素为： ");
    displayList(list1);
    printf("链表2的元素为： ");
    displayList(list2);
    list = mergeTwoLists(list1, list2);
    printf("归并后链表的元素为： ");
    displayList(list);
    destroyList(&list1);
    destroyList(&list2);
    destroyList(&list);
}

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    if (l1 == NULL && l2 == NULL)
        return NULL;
    else {
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;
    }
    struct ListNode *list1 = l1, *list2 = l2, *list = NULL, *prior = NULL, *next = NULL;
    // 第一轮循环，到达其中一条链的链尾，后面的循环其实就是将剩下链的元素直接插入新链表即可
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            if (list == NULL) {
                list = malloc(sizeof(struct ListNode));
                list->val = list1->val;
                prior = list;
            } else {
                next = malloc(sizeof(struct ListNode));
                next->val = list1->val;
                prior->next = next;
                prior = next;
            }
            list1 = list1->next;
        } else {
            if (list == NULL) {
                list = malloc(sizeof(struct ListNode));
                list->val = list2->val;
                prior = list;
            } else {
                next = malloc(sizeof(struct ListNode));
                next->val = list2->val;
                prior->next = next;
                prior = next;
            }
            list2 = list2->next;
        }
    }
    while (list1 != NULL) {
        next = malloc(sizeof(struct ListNode));
        next->val = list1->val;
        prior->next = next;
        prior = next;
        list1 = list1->next;
    }
    while (list2 != NULL) {
        next = malloc(sizeof(struct ListNode));
        next->val = list2->val;
        prior->next = next;
        prior = next;
        list2 = list2->next;
    }
    prior->next = NULL;
    return list;
}