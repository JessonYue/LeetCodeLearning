#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode(-1);
    ListNode *p = head;
    while (l1 && l2) {
        if (l1->val > l2->val) {
            p->next = l2;
            l2 = l2->next;
        } else {
            p->next = l1;
            l1 = l1->next;
        }
        p = p->next;
    }
    p->next = l1 == nullptr ? l2 : l1;
    return head->next;
}

int main() {
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(4);
    a->next = b;
    b->next = c;
    c->next = nullptr;

    ListNode *d = new ListNode(1);
    ListNode *e = new ListNode(3);
    ListNode *f = new ListNode(4);
    d->next = e;
    e->next = f;
    f->next = nullptr;

    ListNode *result = mergeTwoLists(a, d);

    while (result) {
        printf("value is %d\n", result->val);
        result = result->next;
    }
    return 0;
}