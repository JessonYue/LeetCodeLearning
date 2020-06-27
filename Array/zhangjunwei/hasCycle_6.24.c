
#include <stdbool.h>
#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle1(struct ListNode *head) {
    if (head==NULL)return false;
    struct ListNode *fast = head;//一次走两步
    struct ListNode *slow = head;//一次走一步

    while (fast!=NULL && slow!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if (fast==slow)
            return true;
    }
    return false;
}

//堆大小足够的话，操作系统malloc一般是向上生长的，如果链表有环的话，那么next的地址一般比当前地址小

bool hasCycle(struct ListNode *head) {
    struct ListNode *p = head;
    while (p!=NULL && p->next!=NULL){
        if (p->next <= p)//1、指向前面的结点 2、自己指向自己
            return true;
        p = p->next;
    }
    return false;
}