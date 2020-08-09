//
// Created by Vashon on 2020/6/9.
//

#include "homework_007.h"

struct ListNode *mergeTwoLists_1(struct ListNode *l1, struct ListNode *l2) {
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

struct ListNode *mergeTwoLists_2(struct ListNode *l1, struct ListNode *l2) {
    if (!l1 || !l2) return l1 ? l1 : l2;
    struct ListNode head, *temp = &head;
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
    if (l1) temp->next = l1;
    if (l2) temp->next = l2;
    return head.next;
}

struct ListNode *mergeTwoLists_3(struct ListNode *l1, struct ListNode *l2) {
    if (!l1 || !l2) return l1 ? l1 : l2;
    struct ListNode *head = NULL, *temp = NULL;
    bool flag = false;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            if (!temp)
                head = temp = l1;
            else {
                flag = true;
                temp->next = l1;
            }
            l1 = l1->next;
        } else {
            if (!temp)
                head = temp = l2;
            else {
                flag = true;
                temp->next = l2;
            }
            l2 = l2->next;
        }
        if (flag) temp = temp->next;
    }
    if (l1) temp->next = l1;
    if (l2) temp->next = l2;
    return head;
}

struct ListNode *mergeTwoLists_4(struct ListNode *l1, struct ListNode *l2) {
    if (!l1 || !l2) return l1 ? l1 : l2;
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists_4(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists_4(l1, l2->next);
        return l2;
    }
}

// 合并两个有序链表，LeetCode第21题
void homework_007_021(void) {
    struct ListNode *list1 = NULL, *list2 = NULL, *list = NULL;
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
    list = mergeTwoLists_2(list1, list2);
    printf("归并后链表的元素为： ");
    displayList(list);
    destroyList(&list);
}
