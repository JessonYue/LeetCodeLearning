//
// Created by hasee on 2020/6/5.
//
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB){
    struct ListNode *pa = headA;
    struct ListNode *pb = headB;
    while (pa != pb) {
        if (!pa) {
            pa = headB;
        }else{
            pa = pa->next;
        }
        if (!pb) {
            pb = headA;
        }else{
            pb = pb->next;
        }
    }
    return pa;
}