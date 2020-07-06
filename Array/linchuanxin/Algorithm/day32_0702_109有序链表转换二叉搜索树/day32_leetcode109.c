//
// Created by LCX on 2020/7/2.
//
#include <stdio.h>
#include <malloc.h>
  struct ListNode {
      int val;
      struct ListNode *next;
  };

  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };


struct ListNode* findMidNode(struct ListNode* head)
{
    if(head == NULL)
        return NULL;
    struct ListNode *pre = NULL;
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast!= NULL && fast->next != NULL)
    {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(pre != NULL)
    {
        pre->next = NULL;
    }
    return slow;

}

struct TreeNode* sortedListToBST(struct ListNode* head){
    if(head == NULL)
        return NULL;
    struct ListNode *midNode = findMidNode(head);
    struct TreeNode *node =(struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->val = midNode->val;
    node->right = node->left = NULL;
    if(head == midNode)
        return node;
    node->left = sortedListToBST(head);
    node->right = sortedListToBST(midNode->next);
    free(node);
    return node;

}