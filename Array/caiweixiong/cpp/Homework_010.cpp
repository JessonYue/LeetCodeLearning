//
// Created by Vashon on 2020/8/11.
//

#include "Homework_010.h"

ListNode *Homework_010::oddEvenList_1(ListNode *head) {
    if (!head || !head->next || !head->next->next) return head;
    ListNode *sTList = head, *dHList = head->next, *dTList = dHList;
    // 分别用两个指针指向单数节点与双数节点的链头，再用两个指向链尾，迭代到最后就将双数节点的链头链接到单数节点的链尾
    while (sTList->next && dTList->next) {
        sTList->next = dTList->next;
        sTList = sTList->next;
        dTList->next = sTList->next;
        dTList = dTList->next;
    }
    sTList->next = dHList;
    if (dTList)
        dTList->next = nullptr;
    return head;
}

void Homework_010::homework_010_328() {
    ListNode *head;
    createHeadNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
    displayList(head);
    head = oddEvenList_1(head);
    displayList(head);
    destroyList(head);
}