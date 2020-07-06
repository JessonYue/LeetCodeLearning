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

int kthToLast(ListNode *head, int k);

int main() {
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = NULL;
    int value = kthToLast(a, 2);
    printf("value is %d\n", value);
    return 0;
}

/**
 * 思路：快慢指针来实现，先让快指针移动k次，之后快慢指针同时移动，直到快指针结束，
 * 则此时的慢指针为所需的节点位置，因为快慢指针一直保持相距k个节点
 * @param head
 * @param k
 * @return
 */
int kthToLast(ListNode *head, int k) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (k-- > 0) {
        fast = fast->next;
    }
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->val;
}




