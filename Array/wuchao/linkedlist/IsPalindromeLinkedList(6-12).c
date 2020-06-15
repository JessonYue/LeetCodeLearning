//
// Created by 吴超 on 2020/6/12.
//
#include <stdio.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
//通过快慢指针，慢指针一次走一步，快指针一次走两步，当快指针到达尾部时，满指针在链表中部，慢指针在行走时，同时反转前半部分链表
//以1->2->3->2->1 为例，就会得到两个子链表，1<-2<-3和2->1，左半部分链表从节点2开始遍历，右半部分链表从第一个节点遍历，分别对比每一个节点的值
//左半部分链表在遍历时，同时再反转链表，将左半部分链表还原接回右半部分链表，直到右半部分链表到达尾部，如果所有节点值都相等，则是回文链表
bool isPalindrome(struct ListNode* head){
    if(head==NULL||head->next==NULL){
        return true;
    }
    struct ListNode* prev = NULL;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        fast = fast->next->next;
        struct ListNode* temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }
    struct ListNode* rightHead = slow->next;
    struct ListNode* leftHead = prev;
    if(fast->next!=NULL){
        slow->next = prev;
        leftHead = slow;
    }
    bool isPalindrome = true;
    prev = rightHead;
    while (rightHead!=NULL){
        if(leftHead->val!=rightHead->val){
            isPalindrome = false;
        }
        struct ListNode* temp = leftHead->next;
        leftHead->next = prev;
        prev = leftHead;
        leftHead = temp;
        rightHead = rightHead->next;
    }
    return isPalindrome;
}