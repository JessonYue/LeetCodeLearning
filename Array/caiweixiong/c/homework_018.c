//
// Created by Vashon on 2020/6/24.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list_node.h"

// 环型链表，LeetCode第141题
void homework_018_141(void) {
    bool hasCycle(struct ListNode *head);
    Node *head = NULL, *next = NULL, *temp = NULL;
    head = malloc(sizeof(Node));
    head->val = 3;
    next = malloc(sizeof(Node));
    next->val = 2;
    head->next = next;
    temp = next;
    next = malloc(sizeof(Node));
    next->val = 0;
    temp->next = next;
    temp = next;
    next = malloc(sizeof(Node));
    next->val = -4;
    temp->next = next;
    temp = head->next;
    next->next = temp;  // 链表成环
    if (hasCycle(head))
        printf("linker is cycle");
    else
        printf("linker is not cycle");
    next->next = NULL;  // 断开链环
    void destroyList(struct ListNode **list);
    destroyList(&head); // 释放资源
}

bool hasCycle(struct ListNode *head) {
    if (!head || !head->next)
        return false;
    struct ListNode *slow = head, *quick = head;
    while (quick && quick->next) {  // 快慢指针，如果有环，肯定会重合
        quick = quick->next->next;  // 快指针，每次走两步
        slow = slow->next;          // 慢指针，每次走一步
        if (quick == slow) {
            return true;
        }
    }
    return false;
}
