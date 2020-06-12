#include <stddef.h>

//
// Created by 吴超 on 2020/6/10.
//
struct ListNode {
    int val;
    struct ListNode *next;
};

//建立一个dummy节点（哨兵节点）next指向head，current指针从这个节点开始向前走n步
//如果没有到达链表尾部的话，下一步开始prev指针开始和current指针一起行走，那么当current指针走到链表尾部时，prev指针刚好指向倒数第n个节点的前置节点
//将prev的next指针指向prev->next->next，完成倒数第n个节点的删除，然后返回dummy节点的下一个节点即为删除后的head节点
//理解这个算法最关键的是先让current指针走n步，然后prev指针出发，当current指针到达尾部时，prev指针还差n步走到尾部，即还有n个节点没有遍历，那么它下一个节点即为倒数第n个节点。
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode dummy;
    struct ListNode* dummyNode = &dummy;
    dummyNode->next = head;
    struct ListNode* prevNode = dummyNode;
    struct ListNode* currentNode = dummyNode;
    int i = 0;
    while (currentNode->next!=NULL){
        if(i<n){
            i++;
        } else {
            prevNode = prevNode->next;
        }
        currentNode = currentNode->next;
    }
    prevNode->next = prevNode->next->next;
    return dummyNode->next;
}