#include <iostream>
#include <stack>
#include <list>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *convertBiNode(TreeNode *root);

void reversion(TreeNode *root);

int main() {
    return 0;
}

TreeNode *ans = new TreeNode(-1);
TreeNode *cur = ans;

/**
 *
 * @param root
 * @return
 */
TreeNode *convertBiNode(TreeNode *root) {
    reversion(root);
    return ans->right;
}

/**
 * 遍历树结构
 * @param root
 */
void reversion(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    dfs(root->left);
    root->left = NULL;
    cur->right = root;
    cur = root;
    dfs(root->right);
}