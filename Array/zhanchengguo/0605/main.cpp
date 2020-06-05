#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

int main() {
    ListNode *A;
    ListNode *B;
    ListNode *result = getIntersectionNode(A, B);
    printf("value is %d\n", result->val);
    return 0;
}

/**
 * 思路：判断两个链表是否相交，就是判断两个链表的节点是否存在相等的
 * 同时分别从A和B开始出发，走完自己的链表在走对方的，因为是同时，同速，走的总路程是一样的，
 * 如果存在相交的节点，则会出现相等的节点，否则全部走完，则为NULL
 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a = headA;
    ListNode *b = headB;
    while (a != b) {
        if (a == NULL) {
            a = headB;
        } else {
            a = a->next;
        }
        if (b == NULL) {
            b = headA;
        } else {
            b = b->next;
        }
    }
    return a;
}

