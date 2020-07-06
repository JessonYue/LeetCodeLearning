//
// Created by 刘畅 on 2020/7/2.
//

#include "day32.h"
#include "iostream"

struct ListNode {
         int data;
         struct ListNode *next;
     };

 struct TreeNode {
         int data;
         struct TreeNode *left;
         struct TreeNode *right;
     };


ListNode *make(int data);

ListNode *make(int data) {
    ListNode *node = static_cast<ListNode *>(malloc(sizeof(ListNode)));
    assert(node);
    node->data = data;
    node->next = nullptr;
    return node;
}
struct ListNode* FindMidNode(struct ListNode *head, struct ListNode **pprev);
struct TreeNode *sortedListToBST(ListNode *head, ListNode*middleNode);
struct ListNode* FindMidNode(struct ListNode *head, struct ListNode **pprev)
{
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    struct ListNode *prev = NULL;
    while (fast!=NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    *pprev = prev;
    return slow;
}

struct TreeNode* sortedListToBST(struct ListNode* head)
{
    if (head == NULL) {
        return NULL;
    }
    struct ListNode *left;
    struct ListNode *midNode;
    struct ListNode *right;
    midNode = FindMidNode(head, &left);
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (root == NULL) {
        return NULL;
    }
    root->left = NULL;
    root->right = NULL;

    root->data = midNode->data;
    if (left != NULL) {
        left->next = NULL;
        root->left = sortedListToBST(head);
    }
    if (midNode->next != NULL) {
        root->right = sortedListToBST(midNode->next);
    }
    return root;
}

int main() {
    ListNode *node1 = make(-10);
    ListNode *node2 = make(-3);
    node1->next = node2;
    ListNode *node3 = make(0);
    node2->next = node3;
    ListNode *node4 = make(5);
    node3->next = node4;
    ListNode *node5 = make(9);
    node4->next = node5;
    ListNode *node6 = make(0);
    TreeNode *treeNode = sortedListToBST(node1);
//    printf("%d\n",sortedListToBST(node1,5));
//    for (int i = 0; i < 3; ++i) {
//
//    }
    return 0;
}