#include <iostream>
#include <stack>
#include <list>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head);

int main() {
    ListNode *a = new ListNode(3);
    ListNode *b = new ListNode(3);
    ListNode *c = new ListNode(0);
    ListNode *d = new ListNode(-4);
    ListNode *e = new ListNode(9);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = d;
    ListNode* result = detectCycle(a);
    printf("reslut is %d", result->val);
}

/**
 * 思路：快慢指针判断是否有环，有环则交点一定在环上，当双指针都处于交点时，
 * 使得快指针指向head，重新同步走单位节点，则下次相交的节点为开头节点
 * @param head
 * @return
 */
ListNode *detectCycle(ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) {
            break;
        }
    }
    if (fast != slow) {
        return NULL;
    }
    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;

}
