//
// Created by austenYang on 2020/6/27.
//

#include "../ListNode.h"


class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur) {
            ListNode *curNext = cur->next;
            cur->next = pre;
            pre = cur;
            cur = curNext;
        }
        return pre;
    }
};


