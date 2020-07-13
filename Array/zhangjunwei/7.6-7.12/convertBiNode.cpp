//
// Created by 张俊伟 on 2020/7/12.
//
#include <cstdio>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//private:
//    TreeNode *header = new TreeNode(0);
//    TreeNode *cur = header;
//public:
//
//    void inOrder(TreeNode *node){
//        if (node== NULL)return;
//        inOrder(node->left);
//        node->left = NULL;
//        cur->right = node;
//        cur = node;
//        inOrder(node->right);
//    }
//
//    TreeNode *convertBiNode(TreeNode *root) {
//        inOrder(root);
//        return header->right;
//    }
//};

#include <stack>

class Solution {
private:
    TreeNode *header = new TreeNode(0);
    TreeNode *cur = header;
    std::stack<TreeNode *> stack;
public:

    TreeNode *convertBiNode(TreeNode *root) {
        TreeNode *p = root;
        while (p || !stack.empty()) {
            if (p) {
                stack.push(p);
                p = p->left;
            } else {
                p = stack.top();
                stack.pop();
                p->left = nullptr;
                cur->right = p;
                cur = p;

                p = p->right;
            }
        }

        return header->right;
    }
};