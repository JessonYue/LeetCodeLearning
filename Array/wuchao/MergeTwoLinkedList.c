#include <stdio.h>
//
// Created by 吴超 on 2020/6/8.
//
struct ListNode {
    int val;
    struct ListNode *next;
};

//由于之前用java实现过，这次用C实现一遍，思路和合并数组类似。
//新建一个链表来装合并后的链表。分别建立两个指针指向两个链表的头部，对比他们值的大小，将小的节点，链到新链表后面，然后指针（向后移动）指向next，直到一个指针到达链表尾部。
//如果另一个链表还没遍历完，则直接将指针指向的节点链在新链表尾部。
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1==NULL){
        return l2;
    }
    if(l2==NULL){
        return l1;
    }
    struct ListNode head;
    struct ListNode* mergeLinkedListCurrent = &head;
    struct ListNode* mergeLinkedList = mergeLinkedListCurrent;
    struct ListNode* current1 = l1;
    struct ListNode* current2 = l2;
    while (current1!=NULL&&current2!=NULL){
        if(current1->val<current2->val){
            mergeLinkedListCurrent->next = current1;
            current1 = current1->next;
        } else {
            mergeLinkedListCurrent->next = current2;
            current2 = current2->next;
        }
        mergeLinkedListCurrent = mergeLinkedListCurrent->next;
    }
    if (current1!=NULL){
        mergeLinkedListCurrent->next = current1;
    }
    if (current2!=NULL){
        mergeLinkedListCurrent->next = current2;
    }
    return mergeLinkedList->next;
}
