#include <iostream>
#include "alo.h"

int main() {
    auto *l1 = static_cast<ListNode *>(malloc(sizeof(ListNode)));
    l1->val = 1;
    auto *l2 = static_cast<ListNode *>(malloc(sizeof(ListNode)));
    l2->val = 2;
    auto *l3 = static_cast<ListNode *>(malloc(sizeof(ListNode)));
    l3->val = 3;
    auto *l4 = static_cast<ListNode *>(malloc(sizeof(ListNode)));
    l4->val = 4;
    auto *l5 = static_cast<ListNode *>(malloc(sizeof(ListNode)));
    l5->val = 5;
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    ListNode *pNode = removeNthFromEnd(l1, 2);
    std::cout << pNode->val;
    return 0;
}
