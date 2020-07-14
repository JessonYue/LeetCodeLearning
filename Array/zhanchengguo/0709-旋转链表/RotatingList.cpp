#include <iostream>
#include <stack>
#include <list>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *rotateRight(ListNode *head, int k);

int main() {
    ListNode *a = new ListNode(0);
    ListNode *b = new ListNode(1);
    ListNode *c = new ListNode(2);
    ListNode *d = new ListNode(4);
    ListNode *e = new ListNode(5);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = NULL;
    ListNode *result = rotateRight(a, 3);
    while (result) {
        printf("reslut is %d\n", result->val);
        result = result->next;
    }
}

/**
 * 思路：先求出链表长度size，若k取余size为空，那么不用旋转了，直接返回head；
 * 否则将链表首尾相连形成环形链表，由于k表示尾节点向右移动k%size位，那么头节点向右移动size-k%size位，
 * 此时的tail移动size-k%size位到达新头节点的前驱节点，我们仅仅需要保存新头节点，同时断开链表就好了
 * @param head
 * @param k
 * @return
 */
ListNode *rotateRight(ListNode *head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }
    int count = 1;
    ListNode *tail = head;
    while (tail->next) {
        count++;
        tail = tail->next;
    }
    if (k % count == 0) {
        return head;
    }
    tail->next = head;
    int m = count - k % count;
    while (m--) {
        tail = tail->next;
    }
    ListNode *newHead = tail->next;
    tail->next = NULL;
    return newHead;
}