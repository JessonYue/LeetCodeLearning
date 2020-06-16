//
// Created by Vashon on 2020/6/9.
//

#include "list_node.h"
#include <stdio.h>

// 反转链表，LeetCode第206题
void homework_006_206(void) {
    struct ListNode *list = NULL;
    void listInsert(struct ListNode **list, int e);
    void displayList(struct ListNode *list);
    void destroyList(struct ListNode **list);
    struct ListNode *reverseList(struct ListNode *head);
    listInsert(&list, 0);
    listInsert(&list, 9);
    listInsert(&list, 1);
    listInsert(&list, 2);
    listInsert(&list, 4);
    printf("链表反转前的元素为：");
    displayList(list);
    list = reverseList(list);
    printf("链表反转后的元素为：");
    displayList(list);
    destroyList(&list);
}

struct ListNode *reverseList(struct ListNode *head) {
    if (head == NULL)
        return NULL;
    struct ListNode *next = head->next, *temp = NULL;
    // 切断原链
    head->next = NULL;
    while (next) {
        temp = next->next;
        next->next = head;
        head = next;
        next = temp;
    }
    return head;
}