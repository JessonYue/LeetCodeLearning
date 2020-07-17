#include "../../Program Files (x86)/x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include/stdio.h"
#include "../../Program Files (x86)/x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include/malloc.h"

//
// Created by 张佳男 on 2020/7/17.
//
typedef int Key;
/* 数据结构定义 */
typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} NODE;

int insertTree(NODE **tree, Key aa);

void printTree(NODE **tree);

NODE *CreatTree();

int deleteTree(NODE **tree, Key aa);

NODE *treeDeleteMin(node **pNode);

void destroyBST(node *pNode);

/* 主函数 */
int main() {
    NODE *tree = CreatTree();
    insertTree(&(tree), 3);
    insertTree(&(tree), 5);
    insertTree(&(tree), 4);
    insertTree(&(tree), 2);
    insertTree(&(tree), 6);
    insertTree(&(tree), 8);
    insertTree(&(tree), 7);
    insertTree(&(tree), 10);
    insertTree(&(tree), 11);
    insertTree(&(tree), 1);

    printTree(&tree);
    printf("\n");
    deleteTree(&tree, 3);
    printTree(&tree);
    destroyBST(tree);
    printTree(&tree);
    return 0;
}

/**
 * 插入二叉搜索树
 * @return
 */
int insertTree(NODE **tree, Key aa) {
    NODE *root = *tree;
    NODE *parent = nullptr;
    while (root != nullptr) {
        if (root->key == aa) {
            printf("此值已经存在，无需添加\n");
            return -1;
        }
        parent = root;
        if (root->key > aa) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    NODE *newNode = static_cast<NODE *>(malloc(sizeof(NODE)));
    newNode->key = aa;
    newNode->right = newNode->left = nullptr;
    if (parent == nullptr) {
        parent = newNode;
        return 0;
    }
    if (aa < parent->key) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
    return 0;
}


/**
 * build二茬搜索树
 */
NODE *CreatTree() {
    NODE *tree = static_cast<NODE *>(malloc(sizeof(NODE *)));
    tree->key = 0;
    tree->right = tree->left = nullptr;
    return tree;
}

/**
 * 打印二叉树
 * @param tree
 */
void printTree(NODE **tree) {
    if (*tree == nullptr) {
        return;
    }
    printTree(&((*tree)->left));
    printf("%d  ", (*tree)->key);
    printTree(&((*tree)->right));
}

/**
 * 删除二茬搜索树
 * @param tree
 * @param aa
 * @return
 */
int deleteTree(NODE **tree, Key aa) {
    NODE **root = tree,*x ;
    while (root != nullptr) {
        if ((*root)->key == aa) {
            x = *root;
            if (x->left == nullptr && x->right == nullptr) {
                *root = nullptr;
            } else if (x->left == nullptr) {
                *root = x->right;
            } else if (x->right == nullptr) {
                *root = x->left;
            } else {
                * root = treeDeleteMin(&(*root)->right);
                (* root)->right = x->right;
                (* root)->left = x->left;
            }
            free(x);
            return 1;
        } else if ((*root)->key > aa) {
            root = &(*root)->left;
        } else {
            root = &(*root)->right;
        }
    }
    return 0;
}
/**
 * 删除右侧最小树并返回
 * @param pNode
 * @return
 */
NODE *treeDeleteMin(node **pNode) {
    NODE *x; //中间变量
    while ((*pNode)->left != nullptr) {
        pNode = &(*pNode)->left;
    }
    x = *pNode;
    *pNode = x->right;
    return x;
}
/**
 * 销毁树
 * @param pNode
 */
void destroyBST(node *pNode){
    if (pNode) {
        destroyBST(pNode->left);
        destroyBST(pNode->right);
        free(pNode);
        pNode = nullptr;
    }
}