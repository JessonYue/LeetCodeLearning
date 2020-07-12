
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* convertBiNode(struct TreeNode* root){
    if (root == NULL) {
        return NULL;
    }

    struct TreeNode * linkHead = convertBiNode(root->left);
    if (linkHead == NULL) {
        linkHead = root;
    } else {
        struct TreeNode * tmp = linkHead;
        while (linkHead->right != NULL) {
            linkHead = linkHead->right;
        }
        linkHead->right = root;
        linkHead = tmp;
    }
    root->left = NULL;
    root->right = convertBiNode(root->right);
    return linkHead;
}