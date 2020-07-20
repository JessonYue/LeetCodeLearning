/**
 *  Created by 崔继霖 on 2020/7/18.
 *  二叉搜索树 练习
 * */
#include <stdio.h>
#include <stdlib.h>

#define EQUAL 1
#define BIGGER 2
#define SMALLER 3

typedef struct node {
    int value;
    node *left;
    node *right;
} NODE;

NODE *root = NULL;

//insert
NODE *treeInsert(int key);

// delete noe
int treeDelete(int value);

// left -- >mid --> right
void inOrder(NODE *root);

//比较；目标值，节点值
int keyComp(int insertValue, int current);

//找到右子树部分中的最小值
NODE *treeDeleteMin(NODE **p);

void test();

NODE *treeInsert(int key) {
    NODE **p = &root, *newNode;
    int flag;
    while ((*p) != NULL) {
        flag = keyComp(key, (*p)->value);
        if (flag == SMALLER) {
            p = &(*p)->left;
        } else if (flag == BIGGER) {
            p = &(*p)->right;
        } else {
            return NULL;
        }
    }

    if ((newNode = static_cast<NODE *>(malloc(sizeof(NODE)))) == NULL) {
        printf("no memory\n");
    }

    newNode->value = key;
    newNode->left = NULL;
    newNode->right = NULL;
    *p = newNode;
    return newNode;
}

int treeDelete(int value) {
    NODE **p = &root, *x;
    int flag;
    while (*p != NULL) {
        flag = keyComp(value, (*p)->value);
        x = *p;
        if (flag == SMALLER) {
            p = &(*p)->left;
        } else if (flag == BIGGER) {
            p = &(*p)->right;
        } else {
            if ((*p)->left == NULL && ((*p)->right) == NULL) {
                *p = NULL;
            } else if ((*p)->left != NULL && ((*p)->right) != NULL) {

                *p = treeDeleteMin(&x->right);
                (*p)->left = x->left;
                (*p)->right = x->right;

            } else if ((*p)->left == NULL) {
                *p = x->right;
            } else if (((*p)->right) == NULL) {
                *p = x->left;
            }
            free(x);
            return 1;
        }

    }
    return 0;
}

/***
 * 删除右子树中的最小值
 * @param p
 * @return
 */
NODE *treeDeleteMin(NODE **p) {
    NODE *temp;
    while ((*p)->left != NULL) {
        p = &(*p)->left;
    }
    temp = *p;
    (*p) = (*p)->right;
    return temp;
}


int keyComp(int insertValue, int current) {
    if (insertValue > current) {
        return BIGGER;
    } else if (insertValue < current) {
        return SMALLER;
    }
    return EQUAL;
}

void inOrder(NODE *root) {

    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    printf("node = %d \n", root->value);
    inOrder(root->right);
}

void test() {

    treeInsert(6);
    treeInsert(3);
    treeInsert(7);
    treeInsert(9);
    treeInsert(1);
    treeInsert(10);
    treeInsert(8);

    inOrder(root);

    printf("************* treeDelete *************\n");
    treeDelete(9);
    inOrder(root);


}


int main() {
    test();


}