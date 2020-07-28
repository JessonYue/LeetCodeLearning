//
// Created by Vashon on 2020/7/25.
//

#include "Homework_004.h"

ListNode *Homework_004::addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (!l1 && !l2)
        return nullptr;
    ListNode *head = nullptr, *temp1 = l1, *temp2 = l2;
    int mod = 0, overflow = 0, sum = 0;
    while (temp1 || temp2) {  // 只要其中一个链表不是空的，那么就要继续
        sum = overflow;  // 上一次的溢出位应该添加到当前循环的总和
        if (temp1) {
            sum += temp1->val;
            temp1 = temp1->next;
        }
        if (temp2) {
            sum += temp2->val;
            temp2 = temp2->next;
        }
        mod = sum % 10;
        overflow = sum / 10;
        if (!head)   // 首次创建节点
            createHeadNode(head, mod);
        else
            insertNode(head, mod);
        if (!temp1 && !temp2) { // 两条相加的链都已到达链尾
            if (overflow)  // 存在溢出位
                insertNode(head, overflow);
        }
    }

    return head;
}

void Homework_004::homework_004_002() {
    ListNode *list1, *list2, *list = nullptr;
    createHeadNode(list1, 2);
    insertNode(list1, 4);
    insertNode(list1, 3);
    createHeadNode(list2, 5);
    insertNode(list2, 6);
    insertNode(list2, 4);
    displayList(list1);
    displayList(list2);

    list = addTwoNumbers(list1, list2);
    displayList(list);

    destroyList(list1);
    destroyList(list2);
    destroyList(list);
}