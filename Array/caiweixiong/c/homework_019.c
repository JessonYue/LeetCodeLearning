//
// Created by Vashon on 2020/6/28.
//

#include <stdio.h>
#include <stdlib.h>
#include "list_node.h"

// 环路检测，LeetCode面试题02.08
void homework_019_0208(void) {
    // 解题思路
    // 1.通过快慢指针判断链表是否有环，并返回一个元素，如果有环则为环内元素，如果无环，则为空
    // 2.测出头结点到环内每个节点的距离
    struct ListNode *detectCycle(struct ListNode *head);
    // 初始化链表
    Node *head = NULL, *next = NULL, *temp = NULL, *start = NULL;
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
    start = detectCycle(head);
    if (!start)
        printf("linker is not cycle");
    else
        printf("linker cycle ele is : %d", start->val);
    start = NULL;
    next->next = NULL;  // 断开链环
    void destroyList(struct ListNode **list);
    destroyList(&head); // 释放资源
}

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *getCycleElem(struct ListNode *head);
    Node *elem = getCycleElem(head);    // 1.通过快慢指针判断链表是否有环
    if (!elem)    // 不存在环
        return NULL;
    Node *first = head, *start = elem, *next = elem, *temp = elem;
    int count = 1, min = INT_MAX;
    while (next->next != start) {
        while (first != next) {
            first = first->next;
            if (++count > min)  // 当此次统计的元素比上次统计的大时，则跳出循环
                break;
        }
        if (min > count) {              // 2.测出头结点到环内每个节点的距离，取出最小的元素
            min = count;
            temp = first;
        }
        // 重置数据
        count = 1;
        first = head;
        next = next->next;
    }
    return temp;
}

// 从环中得到环内的元素
struct ListNode *getCycleElem(struct ListNode *head) {
    if (!head || !head->next)
        return NULL;
    Node *slow = head, *quick = head, *elem = NULL;
    while (quick->next && quick->next->next) {
        slow = slow->next;
        quick = quick->next->next;
        if (slow == quick) {    // 链表存在环，获取环中的元素
            elem = slow;
            break;
        }
    }
    return elem;
}