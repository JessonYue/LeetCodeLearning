#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB){
    if(headA == NULL||headB == NULL)
        return NULL;
    struct ListNode *p = headA;
    struct ListNode *q = headB;

    while (q != p){
        if (p == NULL) {
            p = headB;
        } else {
            p = p->next;
        }
        if (q == NULL) {
            q = headB;
        } else {
            q = q->next;
        }
    }
    return p;
}