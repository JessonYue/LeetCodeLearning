#include <iostream>


struct ListNode {
    int num;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    struct ListNode *L1, *L2;
    L1 = headA;
    L2 = headB;

    while (L1 != L2) {
        //走相同的长度的路  如果相等一定会相交
        // 123456NULL21456NULL
        // 21456NULL123456NULL
        //456相交
        //如果不相交  到最后都等于NULL退出
        L1 = ((L1 == NULL) ? headB : L1->next);
        L2 = ((L2 == NULL) ? headA : L2->next);
    }
    return L2;

}

int main() {
    return 0;
}