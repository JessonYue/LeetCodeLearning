//
// Created by Vashon on 2020/8/11.
//

#include "Homework_009.h"

ListNode *Homework_009::removeNthFromEnd_1(ListNode *head, int n) {
    if (!head || n <= 0) return head;
    ListNode *slow = head, *fast = head, *target;
    int count = 1;
    // 将快指针先前移 N 个节点后快慢指针一起移动
    while (fast->next) {
        fast = fast->next;
        if (count++ > n)
            slow = slow->next;
    }
    // 当链长需要删除的节点不存在
    if (count < n) return head;
    if (count == n) {   // 需要删除的是头节点
        target = head;
        head = head->next;
    } else {
        target = slow->next;
        slow->next = target->next;
    }
    delete target;
    return head;
}

void Homework_009::homework_009_019() {
    ListNode *head;
    createHeadNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
    displayList(head);
    head = removeNthFromEnd_1(head, 5);
    displayList(head);
    destroyList(head);
}