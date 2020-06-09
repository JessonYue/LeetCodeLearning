//
// Created by 谢涛 on 2020/6/3.
//

#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

int main() {

    return 0;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL){
        return NULL;
    }

    struct ListNode *p = headA;
    struct ListNode *q = headB;
    while (p != q ){
        p = (p == NULL) ? headB : p->next;
        q = (q == NULL) ? headA : q->next;
    }
    return p;
}






