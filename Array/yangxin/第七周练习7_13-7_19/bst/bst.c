//
// Created by 12 on 2020/6/28.
//
#include <stdio.h>
#include <malloc.h>
#include "bst.h"

BsTree *createBsTree() {
    BsTree *bst = malloc(sizeof(BsTree));
    bst->root = NULL;
    return bst;
}

int addNode(BsTree *bst, int val) {
    if (bst == NULL) {
        return NULL;
    }

    if (bst->root == NULL) {
        bst->root = malloc(sizeof(Node));
        bst->root->val = val;
        bst->root->left = NULL;
        bst->root->right = NULL;
    } else {
        Node **p = &bst->root;
        while ((*p) != NULL) {
            if ((*p)->val == val) {
                return NULL;
            }

            if ((*p)->val > val) {
                p = &(*p)->left;
            } else {
                p = &(*p)->right;
            }
        }

        *p = malloc(sizeof(Node));
        (*p)->val = val;
        (*p)->left = NULL;
        (*p)->right = NULL;
    }
    return 1;
}

Node *findNode(BsTree *bst, int val) {
    if (bst == NULL) {
        return NULL;
    }

    Node **p = &bst->root;
    while ((*p) != NULL) {
        if ((*p)->val == val) {
            return *p;
        } else if ((*p)->val > val) {
            p = &(*p)->left;
        } else {
            p = &(*p)->right;
        }
    }

    return NULL;
}

int upDataNode(BsTree *bst, int oldVal, int newVal) {
    if (bst == NULL) {
        return 0;
    }

    Node *node = findNode(bst, oldVal);
    if (node != NULL) {
        node->val = newVal;
    }
    return 1;
}

int deleteNode(BsTree *bst, int val) {
    if (bst == NULL) {
        return 0;
    }
    Node **p = &bst->root;
    Node *tmp;
    while ((*p) != NULL) {
        if ((*p)->val == val) {
            tmp = *p;
            if (tmp->left == NULL && tmp->right == NULL) {
                *p = NULL;
            } else if (tmp->left != NULL) {
                *p = tmp->left;
            } else {
                *p = tmp->right;
            }
            free(tmp);
            return 1;
        } else if ((*p)->val > val) {
            p = &(*p)->left;
        } else {
            p = &(*p)->right;
        }
    }
    return 1;
}

int bstPrint(Node *root) {
    if (root == NULL) {
        return NULL;
    }
    bstPrint(root->left);
    printf("%d->", root->val);
    bstPrint(root->right);
    return 1;
}

int main() {
    BsTree *bst = createBsTree();
    addNode(bst, 3);
    addNode(bst, 2);
    addNode(bst, 1);
    addNode(bst, 5);
    addNode(bst, 4);

    bstPrint(bst->root);

    upDataNode(bst, 5, 6);
    printf("\n");
    bstPrint(bst->root);
    printf("\n");
    deleteNode(bst, 2);
    deleteNode(bst, 6);
    bstPrint(bst->root);
    return 0;
}