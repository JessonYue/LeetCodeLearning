#include <assert.h>
#include <cstdio>
#include <cstring>
#include <malloc.h>
//
// Created by Jesson on 2020/6/18.
//

//定义树的节点 需要知道看懂别人的代码 是对应的什么结构 一般来说底层就是数组和链表
typedef char DataType;
typedef struct TreeNode
{
    DataType elem;
    struct TreeNode* rchild;
    struct TreeNode* lchild;
}TreeNode;

//初始化
void InitTree(TreeNode** root) {
    assert(root);
    if (*root == NULL)
        return;
    *root = NULL;
    return;
}

//递归进行树的前序遍历 根===》左====》右 非递归（方式）
void PreOrder(TreeNode* root) {
    if (root == NULL)
        return;
    printf("%c ", root->elem);
    PreOrder(root->lchild);
    PreOrder(root->rchild);
    return;
}
//中序遍历
void InOrder(TreeNode* root) {
    if (root == NULL)
        return;
    InOrder(root->lchild);
    printf("%c ", root->elem);
    InOrder(root->rchild);
    return;
}
//后序遍历
void PostOrder(TreeNode* root)
{
    if(root == NULL)
        return;
    PostOrder(root->lchild);
    PostOrder(root->rchild);
    printf("%c ", root->elem);
    return;
}
// 根据各种遍历的方式来创建树
TreeNode * CreateTree(char preorder[], int size, int *pUsed) {
    if (size == 0) {
        *pUsed = 0;
        return NULL;
    }
    else if (preorder[0] == '#') {
        *pUsed = 1;
        return NULL;
    }
    else {
        // 根
        TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
        root->elem = preorder[0];
        // 左子树
        int leftUsed;		// 用来保存创建左子树用掉的个数
        int rightUsed;		// 用来保存创建右子树用掉的个数
        root->lchild = CreateTree(preorder + 1, size - 1, &leftUsed);
        root->rchild = CreateTree(
                preorder + 1 + leftUsed,
                size - 1 - leftUsed, &rightUsed);

        *pUsed = 1 + leftUsed + rightUsed; // 根用掉 + 左子树用掉 + 右子树用掉
        return root;
    }
}

int Find(char array[], int size, char v) {
    for (int i = 0; i < size; i++) {
        if (array[i] == v) {
            return i;
        }
    }
    return -1;
}
TreeNode * buildTree(char preorder[], char inorder[], int size) {
    if (size == 0) {
        return NULL;
    }

    char rootValue = preorder[0];
    int leftSize = Find(inorder, size, rootValue);

    // 根
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->elem = rootValue;
    // 左子树
    root->lchild = buildTree(preorder + 1, inorder, leftSize);
    // 右子树
    root->rchild = buildTree(preorder + 1 + leftSize,
                            inorder + leftSize + 1, size - 1 - leftSize);

    return root;
}

void Test1() {
    char *preorder = "ABD##E#H##CF##G";
    int size = strlen(preorder);
    int used;

    TreeNode *root = CreateTree(preorder, size, &used);
    printf("used==>%d",used);
    assert(used == size);
}
void Test2() {
    char *preorder = "ABDEHCFG";
    char *inorder = "DBEHAFCG";
    int size = strlen(preorder);

    TreeNode *root = buildTree(preorder, inorder, size);
}

int main(){
    Test1();
    Test2();
}