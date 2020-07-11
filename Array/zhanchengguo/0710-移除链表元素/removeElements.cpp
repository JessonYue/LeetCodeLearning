#include <iostream>
#include <stack>
#include <list>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeElements(ListNode *head, int val);

int main() {
    ListNode *a = new ListNode(0);
    ListNode *b = new ListNode(1);
    ListNode *c = new ListNode(2);
    ListNode *d = new ListNode(3);
    ListNode *e = new ListNode(4);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = NULL;
    ListNode *result = removeElements(a, 3);
    while (result) {
        printf("reslut is %d\n", result->val);
        result = result->next;
    }
}

ListNode *removeElements(ListNode *head, int val) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *prev = dummy;

    while (prev->next) {
        if (prev->next->val == val) {
            ListNode *tmp = prev->next;
            prev->next = prev->next->next;
            delete tmp;
        } else {
            prev = prev->next;
        }
    }
    return dummy->next;
}
