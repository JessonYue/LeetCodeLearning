//
// Created by Vashon on 2020/7/15.
//

#include <stdlib.h>
#include <stdio.h>
#include "list_node.h"

struct TreeNode *convertBiNode(struct TreeNode *root);

// 二叉树数据结构，把二叉搜索树转换为单向链表，LeetCode面试题17.12.BiNode
void homework_029_1712(void) {
    struct TreeNode *root = NULL, *left = NULL, *right = NULL;
    left = malloc(sizeof(struct TreeNode));
    left->val = 1;
    left->left = left->right = NULL;
    right = malloc(sizeof(struct TreeNode));
    right->val = 3;
    right->left = right->right = NULL;
    root = malloc(sizeof(struct TreeNode));
    root->val = 2;
    root->left = left;
    root->right = right;
    displayTree(root);
    printf("\n");
    displayTree(convertBiNode(root));
    destroyTree(root);
}

struct TreeNode *pre;

// 递归转换，顺序为：最右的叶子 -> 分支 -> 左叶子 -> 上层分支 -> 左叶子 -> ... -> 最左的叶子
void convertBiNode_(struct TreeNode *root, struct TreeNode **r) {
    if (!root)
        return;
    convertBiNode_(root->right, r);
    root->right = pre;
    if (pre)
        pre->left = NULL;
    pre = root;
    *r = root;
    convertBiNode_(root->left, r);
}

struct TreeNode *convertBiNode(struct TreeNode *root) {
    pre = NULL;
    convertBiNode_(root, &root);
    return root;
}













