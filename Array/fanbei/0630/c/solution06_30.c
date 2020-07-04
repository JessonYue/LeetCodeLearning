#include <stdlib.h>
#include <stdio.h>

struct ListNode{
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* node){
    if (node == NULL){
        return NULL;
    }
    struct  ListNode* newHead = NULL;
    struct  ListNode* head = node;
    struct ListNode* tmp = NULL;
    while (head!=NULL){
        tmp = head->next;
        head->next = newHead;
        newHead = node;
        node = tmp;
    }
    return newHead;
}

