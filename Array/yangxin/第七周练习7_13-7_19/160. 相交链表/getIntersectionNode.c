/**
 * 160. 相交链表
 * 编写一个程序，找到两个单链表相交的起始节点。
 */
struct ListNode *getIntersectionNode1(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    if (headA == headB) {
        return headA;
    }
    int sizeA = 0;
    int sizeB = 0;
    struct ListNode *tailA = headA;
    struct ListNode *tailB = headB;
    while (tailA->next != NULL) {
        sizeA++;
        tailA = tailA->next;
    }

    while (tailB->next != NULL) {
        sizeB++;
        tailB = tailB->next;
    }

    if (tailA != tailB) {
        return NULL;
    }

    int diff = sizeA - sizeB;
    if (diff > 0) {
        tailA = headA;
        tailB = headB;
    } else {
        tailA = headB;
        tailB = headA;
        diff = -diff;
    }

    while (diff > 0) {
        tailA = tailA->next;
        diff--;
    }

    while (tailA != tailB) {
        tailA = tailA->next;
        tailB = tailB->next;
    }

    return tailA;
}