//
// Created by 谢涛 on 2020/6/30.
//
#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct ListNode* preMid(struct ListNode* head){
    struct ListNode* prevPtr = NULL;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast != NULL && fast->next != NULL){
        prevPtr = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(prevPtr != NULL){
        prevPtr->next = NULL;
    }

    return slow;
}


struct TreeNode* sortedListToBST(struct ListNode* head){
    if(head == NULL){
        return NULL;
    }
    struct ListNode* min = preMid(head);
    struct TreeNode* node=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = min->val;
    if(min->val == head->val){
        return node;
    }
    node->left = sortedListToBST(head);
    node->right = sortedListToBST(min->next);
    return node;
}
int main() {

    return 0;
}