//
// Created by 张俊伟 on 2020/7/1.
//
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *newTreeNode(int val) {
    struct TreeNode *root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->val = val;
    root->left = root->right = NULL;
    return root;
}

struct ListNode *findMidpreNode(struct ListNode *head) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    struct ListNode *pre = head;

    while (fast != NULL && fast->next != NULL) {
        pre = slow;
        fast = fast->next->next;
        slow = slow->next;
    }

    return pre;
}

struct TreeNode *sortedListToBST(struct ListNode *head) {
    if (head == NULL)return NULL;
    if (head->next == NULL) return newTreeNode(head->val);
    struct ListNode *preMid = findMidpreNode(head);
    struct ListNode *mid = preMid->next;
    struct ListNode *nextMid = mid->next;
    preMid->next = NULL;
    struct TreeNode *root = newTreeNode(mid->val);
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(nextMid);
    return root;
}
/*
struct TreeNode *newTreeNode(int val) {
    struct TreeNode *root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->val = val;
    root->left = root->right = NULL;
    return root;
}

void insertNode(struct TreeNode *root, struct ListNode *node) {
    if (node != NULL) {
        struct TreeNode **cur = &root;
        while (*cur != NULL) {
            cur = (node->val < (*cur)->val) ? &(*cur)->left : &(*cur)->right;
        }
        struct TreeNode *newNode = newTreeNode(node->val);
        *cur = newNode;
    }
}

struct TreeNode *sortedListToBST(struct ListNode *head) {
    if (head == NULL)return NULL;
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    //遍历完之后 slow 指向
    struct ListNode *mid = slow;
    struct ListNode *left = head;
    struct ListNode *right = mid->next;
    struct TreeNode *root = newTreeNode(mid->val);

    while (left != mid) {
        insertNode(root, left);
        left = left->next;
    }
    while (right != NULL) {
        insertNode(root, right);
        right = right->next;
    }
    return root;
}
 */

