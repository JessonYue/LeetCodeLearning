//
// Created by Vashon on 2020/8/10.
//

#include "Homework_006.h"

ListNode *Homework_006::getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) return nullptr;
    int lenA = 1, lenB = 1;
    ListNode *listA = headA, *listB = headB;
    // 得到两条链的链长
    while (listA->next) {
        listA = listA->next;
        lenA++;
    }
    while (listB->next) {
        listB = listB->next;
        lenB++;
    }
    // 如果链尾相等，则肯定是相交的链
    if (listA == listB) {
        int diff = lenA - lenB; // 得到两条链的长度差
        listA = headA, listB = headB;
        // 让两条链离相交的位置距离相等
        if (diff > 0) {
            while (diff--) listA = listA->next;
        } else {
            while (diff++) listB = listB->next;
        }
        while (listA && listB) {
            if (listA == listB) return listA;
            listA = listA->next;
            listB = listB->next;
        }
    }
    return nullptr;
}

void Homework_006::homework_006_160() {

}