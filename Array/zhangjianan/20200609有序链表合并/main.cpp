//
// Created by 张佳男 on 2020/6/9.
//

#include <iostream>
#include <cstring>


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *heed = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *cash = heed;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            cash->next = l1;
            l1 = l1->next;
        } else {
            cash->next = l2;
            l2 = l2->next;
        }
        cash = cash->next;
    }
    cash->next = l1 == NULL ? l2 : l1;
    return heed->next;
}
int main() {
    return 0;
}