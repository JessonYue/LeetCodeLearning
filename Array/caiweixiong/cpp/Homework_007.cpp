//
// Created by Vashon on 2020/8/10.
//

#include "Homework_007.h"

ListNode *Homework_007::reverseList_1(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode tempHead(0), *temp;
    // 头插法建链
    while (head) {
        temp = head;
        head = head->next;
        temp->next = tempHead.next;
        tempHead.next = temp;
    }
    return tempHead.next;
}

ListNode *Homework_007::reverseList_2(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *newHead = reverseList_2(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

void Homework_007::homework_007_206() {
    ListNode *head;
    createHeadNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
    displayList(head);
    head = reverseList_1(head);
    displayList(head);
    destroyList(head);
}