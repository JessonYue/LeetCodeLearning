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

bool hasCycle(ListNode *head);

int main() {
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = c;
    bool result = hasCycle(a);
    printf("params2 is %d", result);
    free(a);
    free(b);
    free(c);
    free(d);
    return 0;
}

/**
 * 思路：快慢指针的方式，判断是否相遇，相遇则说明有环，否则快指针先到达链表尾部
 * @param head
 * @return
 */
bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}



