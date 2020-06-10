//
// Created by 张佳男 on 2020/6/9.
//

#include <iostream>
#include <cstring>


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode *reverseList(struct ListNode *head) {
    struct ListNode *pre = NULL;
    struct ListNode *cur = head;
    while (cur != NULL) {
        struct ListNode *catchnode = cur->next;
        cur->next = pre;
        pre = cur;
        cur = catchnode;

    }
    return pre;
}

int main() {
    return 0;
}