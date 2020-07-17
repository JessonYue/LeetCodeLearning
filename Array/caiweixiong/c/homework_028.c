//
// Created by Vashon on 2020/7/15.
//

#include <stdlib.h>
#include "list_node.h"

struct ListNode *removeElements(struct ListNode *head, int val);

void listInsert(struct ListNode **list, int e);

void displayList(struct ListNode *list);

void destroyList(struct ListNode **list);

// 移除链表元素，LeetCode第203题
void homework_028_203(void) {
    struct ListNode *list;
    listInsert(&list, 1);
    listInsert(&list, 2);
    listInsert(&list, 6);
    listInsert(&list, 3);
    listInsert(&list, 4);
    listInsert(&list, 5);
    listInsert(&list, 6);
    displayList(list);
    displayList(removeElements(list, 6));
    destroyList(&list);
}

struct ListNode *removeElements(struct ListNode *head, int val) {
    if (!head)
        return head;

    struct ListNode *pre = head, *next = head->next, *newHead = head;

    while (next) {
        if (pre->val == val) {  // 是目标节点
            if (newHead == pre) // 目标节点是头节点
                newHead = pre->next;
            free(pre);
            pre = next;
            next = next->next;
        } else {
            if (next->val == val) {
                pre->next = next->next;
                free(next);
                next = pre->next;
            } else {
                pre = next;
                next = next->next;
            }
        }
    }

    if (pre->val == val) {  // 是目标节点
        if (newHead == pre) // 目标节点是头节点
            newHead = pre->next;
        free(pre);
    }
    return newHead;
}













