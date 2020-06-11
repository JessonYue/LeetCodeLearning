#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *p = dummyHead;
        ListNode *q = dummyHead;
        for (int i = 0; i < n + 1; ++i) {
            q = q->next;
        }
        while (q) {
            p = p->next;
            q = q->next;
        }
        //当q指针指向链表末尾的时候，这时候p指针到达n节点处
        ListNode *delNode = p->next;
        //将p指针当前节点指向需要删除的节点的下个节点
        p->next = delNode->next;
        delete delNode;

        ListNode *resultNode = dummyHead->next;
        delete dummyHead;

        return resultNode;
    }
};