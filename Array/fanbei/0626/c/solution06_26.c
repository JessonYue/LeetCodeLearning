#include <stdlib.h>
#include <stdio.h>

/**
 * 删除链表中的节点
 */
struct ListNode{
    int val;
    struct ListNode* next;
};

void deleteNode(struct  ListNode* node){
    node->val = node->next->val;
    node->next = node->next->next;
}

int main(){}


