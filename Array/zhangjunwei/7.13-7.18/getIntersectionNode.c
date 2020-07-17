//
// Created by 张俊伟 on 2020/7/16.
//

#include <stdbool.h>
#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

//ac+cb = bc+ca
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (!headA || !headB)return NULL;
    struct ListNode *pa = headA;
    struct ListNode *pb = headB;

    bool flag = true;
    while (pa) {
        if (pa == pb)break;
        pa = pa->next;
        pb = pb->next;
        if (!pa && flag) {
            pa = headB;
            flag = false;
        }
        if (!pb)
            pb = headA;
    }
    return pa;
}