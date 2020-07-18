//
// Created by 张俊伟 on 2020/7/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define EMPTY 0
#define EQUAL 1
#define BIGGER 2
#define SMALLER 3

#define DATA int
typedef struct node {
    DATA key;
    struct node *left;
    struct node *right;
} Node;

/* 树的建立与初始化 */
Node *root = NULL;
size_t  node_size = 0;

//比较；目标值，节点值
int keyCompare(DATA k1, DATA k2);

//搜索与key相等的结点；root作为搜索开始
Node *treeFind(DATA key);

//销毁
void destotyTree();

//插入
Node *treeInsert(DATA key);

//删除 key 所在的结点 成功删除return 1 否则 0
int *treeDelete(DATA key);

//找到右子树部分中的最小值
Node *treeDeleteMin(Node **p);

//中序遍历
void treeView(Node *p);

int keyCompare(DATA k1, DATA k2) {
    if (k1 == k2)
        return EQUAL;
    else if (k1 < k2)
        return SMALLER;
    else if (k1 > k2)
        return BIGGER;
}

Node *treeFind(DATA key) {
    Node *p = root;
    int comp;
    while (p != NULL) {
        comp = keyCompare(key, p->key);
        switch (comp) {
            case SMALLER:
                p = p->left;
                continue;
            case BIGGER:
                p = p->right;
                continue;
            case EQUAL:
                return p;
        }
    }
    return NULL;
}

Node *treeInsert(DATA key) {
    Node **p = &root;
    Node *newNode;
    int flag;
    while (*p != NULL) {
        flag = keyCompare(key, (*p)->key);
        if (flag == SMALLER) {
            *p = (*p)->left;
        } else if (flag == BIGGER) {
            *p = (*p)->right;
        } else if (flag == EQUAL)
            return NULL;
    }
    if ((newNode = (Node *) malloc(sizeof(Node))) == NULL) {
        printf("no memory\n");
        exit(0);
    }
    newNode->key = key;
    newNode->left = newNode = NULL;
    *p = newNode;

    node_size++;
    return newNode;
}

int *treeDelete(DATA key) {
    Node **p = &root, *x;
    int flag;
    while ((*p) != NULL) {
        x = *p;
        flag = keyCompare(key, (*p)->key);
        if (flag == SMALLER) {
            p = &(*p)->left;
        } else if (flag == BIGGER) {
            p = &(*p)->right;
        } else if (flag == EQUAL) {
            //没左右孩子
            if (x->left == NULL && x->right == NULL) {
                *p = NULL;
            } //只有一个孩子
            else if (x->right == NULL) {//只有左孩子
                *p = x->left;
            } else if (x->left == NULL) {
                *p = x->right;
            } else {//有两个孩子
                Node *successor = treeDeleteMin(&x->left);
                (*p)->key = successor->key;
                x = successor;
            }
            free(x);
            node_size--;
            return 1;
        }
    }
    return 0;
}

//  p指向当前结点的父结点  *p指向当前结点 （孩子双亲表示）
Node *treeDeleteMin(Node **p) {
    Node *x;
    while ((*p)->left != NULL) {
        p = &(*p)->left;
    }
    x = *p;
    p = &x->right;
    return x;
}

//中序遍历
void treeView(Node *p) {
    if (p == NULL)return;
    treeView(p->left);
    printf("  %d", p->key);
    treeView(p->right);
}

void _destotyTree(Node *p) {
    if (p == NULL)return;
    _destotyTree(p->left);
    _destotyTree(p->right);
    p->left = p->right = NULL;
    free(p);
}

//销毁
void destotyTree() {
    _destotyTree(root);
}

