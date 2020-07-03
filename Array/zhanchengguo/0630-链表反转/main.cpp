#include <iostream>
#include "stack"
#include "string"
#include "vector"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseList1(ListNode *head);

ListNode *reverseList2(ListNode *head);

int main() {
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = NULL;
    ListNode *result = reverseList1(a);
    while (result != nullptr) {
        printf("method 1 value is %d\n", result->val);
        result = result->next;
    }
    printf("\n");

    ListNode *e = new ListNode(5);
    ListNode *f = new ListNode(6);
    ListNode *g = new ListNode(7);
    ListNode *h = new ListNode(8);
    e->next = f;
    f->next = g;
    g->next = h;
    h->next = NULL;
    ListNode *result1 = reverseList2(e);
    while (result1 != nullptr) {
        printf("method 2 value is %d\n", result1->val);
        result1 = result1->next;
    }
    return 0;
}

/**
 * 递归
 * @param head
 * @return
 */
ListNode *reverseList1(ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode *lastNode = reverseList1(head->next);
    head->next->next = head;
    head->next = NULL;
    return lastNode;
}

/**
 * 双指针
 * @param head
 * @return
 */
ListNode *reverseList2(ListNode *head) {
    ListNode *pre = NULL;
    ListNode *current = head;
    while (current != NULL) {
        ListNode *tem = current->next;
        current->next = pre;
        pre = current;
        current = tem;
    }
    return pre;
}




