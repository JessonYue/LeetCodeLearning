#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)

int main() {
    ListNode *a = new ListNode();
    ListNode *b = new ListNode();
    ListNode *c = mergeTwoLists(a, b);
    return 0;
}


/**
 * 思路：用迭代的方法来实现上述算法
 * 当 l1 和 l2 都不是空链表时，判断 l1 和 l2 哪一个链表的头节点的值更小，
 * 将较小值的节点添加到结果里，当一个节点被添加到结果里之后，将对应链表中的节点向后移一位
 *
 */
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *newList = new ListNode(-1);
    ListNode *preNode = newList;
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val > l2->val) {
            preNode->next = l2;
            l2 = l2->next;
        } else {
            preNode->next = l1;
            l1 = l1->next;
        }
        preNode = preNode->next;
    }
    if (l1 == nullptr) {
        preNode->next = l2;
    } else {
        preNode->next = l1;
    }
    return newList->next;
}
