//
// Created by 吴超 on 2020/6/11.
//
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
//思路是prev指针指向head，current指针指向head->next，将prev的next指针指向current的下一个节点，然后prev向前走一步，current向前走一步
//直到current指针指向链表尾部。这样我们就将链表分成了奇数链表和偶数链表。在遍历之前将偶数链表的头部（即current）用evenHead指向。遍历完之后将奇数链表的尾节点的next指针指向evenHead
//current指针到达链表尾部时，这里要分两种情况，当总节点数是奇数时，current指针正好指向的是奇数链表尾部。而如果总结点数是偶数时，则prev指针指向的是奇数链表的尾部。
struct ListNode* oddEvenList(struct ListNode* head){
    if(head==NULL||head->next==NULL||head->next->next==NULL){
        return head;
    }
    int n = 0;
    struct ListNode* prev = head;
    struct ListNode* current = head->next;
    struct ListNode* evenHead = current;
    while(current->next!=NULL){
        n++;
        prev->next = current->next;
        prev = current;
        current = current->next;
    }
    if(n%2!=0){
        //节点数为奇数时，这一步必须执行，不然会使链表成环
        prev->next = NULL;
        current->next = evenHead;
    } else {
        prev->next = evenHead;
    }
    return head;
}