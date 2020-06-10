#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseList(ListNode *head);

ListNode *reverseList2(ListNode *head);

int main() {
    // 双指针
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = NULL;
    ListNode *result = reverseList(a);
    while (result != nullptr) {
        printf("method 1 value is %d\n", result->val);
        result = result->next;
    }

    // 递归
    ListNode *e = new ListNode(1);
    ListNode *f = new ListNode(2);
    ListNode *g = new ListNode(3);
    ListNode *s = new ListNode(4);
    e->next = f;
    f->next = g;
    g->next = s;
    s->next = NULL;
    ListNode *result2 = reverseList2(e);
    while (result2 != nullptr) {
        printf("method 2 value is %d\n", result2->val);
        result2 = result2->next;
    }
    return 0;
}

/**
 * 思路：双指针的方式实现反转
 * 1、定义两个指针分别指向前一个节点和当前节点
 * 2、每次让当前节点的next指向前一个节点，实现局部反转
 * 3、局部反转后，两指针向前移位
 * 4、循环执行上述过程，直至当前节点为null
 * @return
 */
ListNode *reverseList(ListNode *head) {
    ListNode *pre = NULL;
    ListNode *current = head;
    while (current != NULL) {
        ListNode *next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    return pre;
}

/**
 * 思路：递归
 * 从当前节点递归到最后一个节点，最后一个节点就是反转的头节点
 * 每次返回，都让当前节点都next节点指向当前节点，当前节点指向null
 * 直至这个递归结束
 * @return
 */
ListNode *reverseList2(ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode *lastNode = reverseList2(head->next);
    head->next->next = head;
    head->next = NULL;
    return lastNode;
}
