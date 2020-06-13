#include <stdio.h>

struct ListNode *addEventList(struct ListNode *node);

struct ListNode {
    int val;
    struct ListNode *next;
};

int main() {
    printf("Hello, World!\n");
    struct ListNode *head;

    struct ListNode *listNode = addEventList(head);
    return 0;
}

struct ListNode *addEventList(struct ListNode *head) {
    if (head == NULL)return head;

    struct ListNode *o = head;//奇数
    struct ListNode *e = head->next;//偶数
    struct ListNode *e1 = head->next;//第一个偶数
    if (o->next!= NULL && e->next!= NULL) {
        o->next = o->next->next;
        o = o->next;
        e->next = e->next->next;
        e = e->next;
    }
    o->next = e1;//将最后一个奇数节点指向第一个偶数节点
    return head;
}


