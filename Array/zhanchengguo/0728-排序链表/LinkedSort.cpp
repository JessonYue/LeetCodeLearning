#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *sortList(ListNode *head);

ListNode *twoWayMerge(ListNode *l1, ListNode *l2);

/**
 * 分链，查找中心点，断链
 * @param head
 * @return
 */
ListNode *sortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode *pmid;
    ListNode *mid = head;
    ListNode *tail = head;
    while (tail && tail->next) {
        pmid = mid;
        mid = mid->next;
        tail = tail->next->next;
    }
    pmid->next = nullptr;
    return twoWayMerge(sortList(head), sortList(mid));
}

/**
 * 进行二路并归：两条链表分别比较，最小值插入链表头部
 * @param l1
 * @param l2
 * @return
 */
ListNode *twoWayMerge(ListNode *l1, ListNode *l2) {
    ListNode header(-1);
    ListNode *p = &header;
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
    return header.next;
}

int main() {
    ListNode *a = new ListNode(4);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(1);
    ListNode *d = new ListNode(3);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = nullptr;
    ListNode *result = sortList(a);

    while (result) {
        printf("value is %d\n", result->val);
        result = result->next;
    }


    return 0;
}