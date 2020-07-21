//
// Created by Vashon on 2020/7/16.
//

#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

#define MAX_SIZE 30

void homework_btree(void) {
    BTNode *btree = NULL;
    create_btree(&btree, "1(2,3(4,6(,7)))");
    printf("tree depth is : %d\n", btree_depth(btree));
    display_btree(btree);
    destroy_btree(btree);
}

// 这是一个自定义的通过字符串快速创建二叉树的算法，字符串格式为：A(B,C(D(F,G),E))
void create_btree(BTNode **btree, char *str) {
    if (!str)
        return;
    BTNode *btarr[MAX_SIZE], *p = NULL;
    int top = -1, k, j = 0;
    char ch = str[j];
    *btree = NULL;
    while (ch != '\0') {
        switch (ch) {
            case '(':
                top++;
                btarr[top] = p;
                k = 1;
                break;
            case ')':
                top--;
                break;
            case ',':
                k = 2;
                break;
            default:
                p = malloc(sizeof(BTNode));
                p->val = ch;
                p->lchild = p->rchild = NULL;
                if (!(*btree))
                    *btree = p;
                else {
                    switch (k) {
                        case 1:
                            btarr[top]->lchild = p;
                            break;
                        case 2:
                            btarr[top]->rchild = p;
                            break;
                        default:
                            break;
                    }
                }
        }
        ch = str[++j];
    }
}

BTNode *find_node(BTNode *btree, int x) {
    if (!btree)
        return NULL;
    else if (btree->val == x)
        return btree;
    else {
        BTNode *p = NULL;
        p = find_node(btree->lchild, x);
        if (p)
            return p;
        else
            return find_node(btree->rchild, x);
    }
}

int btree_depth(BTNode *btree) {
    if (!btree)
        return 0;
    else {
        int lchildh = 0, rchildh = 0;
        lchildh = btree_depth(btree->lchild);
        rchildh = btree_depth(btree->rchild);
        return lchildh > rchildh ? lchildh + 1 : rchildh + 1;
    }
}

void display_btree(BTNode *btree) {
    if (!btree)
        return;
    printf("%c", btree->val);
    if (btree->lchild || btree->rchild) {
        printf("(");
        display_btree(btree->lchild);
        if (btree->rchild)
            printf(",");
        display_btree(btree->rchild);
        printf(")");
    }
}

void destroy_btree(BTNode *btree) {
    if (!btree)
        return;
    destroy_btree(btree->lchild);
    destroy_btree(btree->rchild);
    free(btree);
    btree = NULL;
}