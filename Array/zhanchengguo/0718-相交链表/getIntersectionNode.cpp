#include <iostream>

using namespace std;

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
    printf("result is %d\n", result->val);
    return 0;
}

/**
 * 思路：两个不同的节点分别从A,B出发，同速同步长，A到链尾从B再次开始，B到链尾从A开始，当A和B相等时相交，否则无交点
 * @param headA
 * @param headB
 * @return
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