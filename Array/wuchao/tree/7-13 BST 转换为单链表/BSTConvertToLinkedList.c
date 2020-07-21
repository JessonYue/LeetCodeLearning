#include <stdlib.h>

//
// Created by 吴超 on 2020/7/13.
//
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *convertBiNode(struct TreeNode *root) {
    if (root == NULL) {
        return NULL;
    }
    struct TreeNode *leftHead = convertBiNode(root->left);
    root->left = NULL;
    struct TreeNode *head = leftHead;
    if (head == NULL) {
        head = root;
    } else {
        while (leftHead->right != NULL) {
            leftHead = leftHead->right;
        }
        leftHead->right = root;
    }
    root->right = convertBiNode(root->right);
    return head;
}
