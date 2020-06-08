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
    printf("result is %d\n", result->val);
    return 0;
}

/**
 * 思路：让两个链表从同距离末尾同等距离的位置开始遍历
 * 1、指针 pA 指向 A 链表，指针 pB 指向 B 链表，依次往后遍历
 * 2、如果 pA 到了末尾，则 pA = headB 继续遍历
 * 3、如果 pB 到了末尾，则 pB = headA 继续遍历
 * 4、比较长的链表指针指向较短链表head时，长度差就消除了
 * 5、如此，只需要将最短链表遍历两次即可找到位置
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

