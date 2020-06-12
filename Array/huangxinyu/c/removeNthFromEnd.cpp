//
// Created by hasee on 2020/6/11.
//

#include "alo.h"
#include <iostream>
#include <cstdio>
/**
 *
 * 双指针方法，第一个指针先走n个节点，然后第二个指针和第一个指针一起走，直到第一个指针到达末尾，说明第二个指针正好到了倒数第n个节点。
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
    auto *preHead = static_cast<ListNode *>(malloc(sizeof(ListNode)));
    preHead->next = head;
    auto *p1 = head;
    int i = 0;
    // p1指针先走n个节点，这样到时候p2指针会走到要删除的节点前一个
    while (i < n) {
        p1 = p1->next;
        i++;
    }
    auto *p2 = preHead;
    while (p1!= nullptr) {
        p1 = p1->next;
        p2 = p2->next;
    }
    p2->next = p2->next->next;
    return preHead->next;
}