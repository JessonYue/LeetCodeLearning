//
// Created by 吴超 on 2020/7/14.
//
#include <stdlib.h>
#include <stdio.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
typedef struct BinarySearchTree {
    TreeNode *root;
} BinarySearchTree;

void print(TreeNode *root);

void printBST(BinarySearchTree *bst);

BinarySearchTree *makeBST();

void freeBST(BinarySearchTree *bst);

TreeNode *makeNode(int val);

void addNode(BinarySearchTree *bst, int val);
TreeNode * getNode(BinarySearchTree *bst, int val);

TreeNode *removeNode(BinarySearchTree *bst, int val);

BinarySearchTree *makeBST() {
    BinarySearchTree *bst = malloc(sizeof(BinarySearchTree));
    bst->root = NULL;
    return bst;
}

TreeNode *makeNode(int val) {
    TreeNode *node = malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void addNode(BinarySearchTree *bst, int val) {
    TreeNode *root = bst->root;
    TreeNode *insertNode = makeNode(val);
    if (root == NULL) {
        root = makeNode(val);
        bst->root = root;
        return;
    }
    while (root != NULL) {
        if (root->val == val) {
            return;
        }
        if (root->val > val) {
            if (root->left != NULL) {
                root = root->left;
                continue;
            }
            root->left = insertNode;
            break;
        } else {
            if (root->right != NULL) {
                root = root->right;
                continue;
            }
            root->right = insertNode;
            break;
        }
    }
}

TreeNode * getNode(BinarySearchTree *bst, int val){
    TreeNode * root = bst->root;
    while (root!=NULL){
        if(root->val == val){
            return root;
        }
        if(root->val>val){
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return NULL;
}

/**
 * 删除节点，二级指针操作，删除很方便，只需操作(*root) 即可，不用父节点(断开)
 * 因为root 已经指向父节点的左节点或右节点的指针了,操作(*root)就是操作父节点的这个指针
 * @param bst
 * @param val
 * @return
 */
TreeNode *removeNode(BinarySearchTree *bst, int val) {
    TreeNode **root = &bst->root;
    while (((*root)) != NULL) {
        if ((*root)->val == val) {
            if ((*root)->left == NULL && (*root)->right == NULL) {
                TreeNode * node = *root;
                (*root) = NULL;
                return node;
            }
            TreeNode **newRoot = NULL;
            if ((*root)->left == NULL) {
                *root = (*root)->right;
            } else if ((*root)->right == NULL) {
                *root = (*root)->left;
            } else {
                if ((*root)->right != NULL) {
                    newRoot = &(*root)->right;
                    while ((*newRoot)->left != NULL) {
                        newRoot = &(*newRoot)->left;
                    }
                    TreeNode * node = *newRoot;
                    *newRoot = node->right;
                    TreeNode * r = *root;
                    *root = node;
                    (*root)->left = r->left;
                    (*root)->right= r->right;
                }

            }
            return *root;
        }
        if ((*root)->val > val) {
            if ((*root)->left != NULL) {
                root = &(*root)->left;
                continue;
            }
            return NULL;
        } else {
            if ((*root)->right != NULL) {
                root = &(*root)->right;
                continue;
            }
            return NULL;
        }
    }
    return NULL;
}

void freeNode(TreeNode** node){
    if((*node)==NULL){
        return;
    }
    if((*node)->left!=NULL){
        TreeNode * left = (*node)->left;
        (*node)->left = NULL;
        freeNode(&left);
    }
    if((*node)->right!=NULL){
        TreeNode * right = (*node)->right;
        (*node)->right = NULL;
        freeNode(&right);
    }
    TreeNode * root = *node;
    (*node) = NULL;
    free(root);
}

void freeBST(BinarySearchTree *bst){
    freeNode(&bst->root);
}

void printBST(BinarySearchTree *bst) {
    print(bst->root);
}

void print(TreeNode *root) {
    if (root == NULL) {
        printf("bst is NULL");
        return;
    }
    if (root->left != NULL) {
        print(root->left);
    }
    printf("%d\n", root->val);
    if (root->right != NULL) {
        print(root->right);
    }
}

int main() {
    BinarySearchTree *bst = makeBST();
    addNode(bst, 10);
    addNode(bst, 3);
    addNode(bst, 56);
    addNode(bst, 100);
    addNode(bst, -89);
    addNode(bst, -1);
    addNode(bst,4);
    addNode(bst, 37);
    printBST(bst);
    removeNode(bst, 3);
    printf("-----------\n");
    printBST(bst);
    TreeNode * node = getNode(bst,100);
    if(node==NULL){
        printf("get node NULL");
    } else {
        printf("get node:%d\n",node->val);
    }
    removeNode(bst, 100);
    printf("-----------\n");
    printBST(bst);
    TreeNode * node2 = getNode(bst,100);
    if(node2==NULL){
        printf("get node NULL\n");
    } else {
        printf("get node:%d\n",node2->val);
    }
    freeBST(bst);
    printBST(bst);
}

