//
// Created by andylin on 2020/7/18.
//
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define EMPTY 0
#define EQUAL 1
#define BIGGER 2
#define SMALLER 3


typedef struct node{
    int key;
    struct node *left;
    struct node *right;
}NODE;

NODE *root = NULL;

int keyComp (int key, int cur_key);
//比较目标值和节点值
int keyComp (int key, int cur_key)
{
    if(key == cur_key)
        return EMPTY;
    else if(key > cur_key)
        return BIGGER;
    return SMALLER;
}

NODE * treeSearch (int key)
{
    NODE *p = root;
    int flag;
    while (p != NULL)
    {
        flag = keyComp(key,p->key);
        if(flag == EQUAL)
            return p;
        else if (flag == BIGGER)
            p = p->right;
        else
            p = p->left;
    }
    return NULL;
}

NODE * treeInsert (int key)
{
    NODE **p = &root, *newNode;
    int flag;
    while ((*p) != NULL){

        flag = keyComp(key, (*p)->key);

        if(flag == EQUAL)
            return NULL;
        else if (flag == BIGGER)
            p = &(*p)->right;
        else
            p = &(*p)->left;
    }

    if((newNode = (NODE *)malloc(sizeof(NODE))) == NULL){
        printf("no memory\n");
        exit(0);
    }

    newNode->left = NULL;
    newNode->right = NULL;
    newNode->key = key;
    *p = newNode;

    return newNode;
}
NODE * treeDeleteMin (NODE **p);
int treeDelete (int key)
{
    NODE **p = &root, *x;
    int flag;
    while((*p) != NULL){
        flag = keyComp(key, (*p)->key);
        x = *p;
        if (flag == EQUAL){
            if ((x->right == NULL) && (x->right == NULL))
                *p = NULL;
            else if (x->right == NULL)
                *p = x->left;
            else if (x->left == NULL)
                *p = x->right;
            else{
                *p = treeDeleteMin(&x->right);
                (*p)->left = x->left;
                (*p)->right = x->right;
            }
            free(x);
            return 1;
        }
        else if (flag == BIGGER)
            p = &(*p)->right;
        else
            p = &(*p)->left;
    }
    return 0;
}

NODE * treeDeleteMin (NODE **p)
{
    NODE *x; //中间变量
    while ((*p)->left != NULL)
        p = &((*p)->left);
    x = *p;
    *p = x->right;

    return x;
}

void treeView (NODE *p)
{
    if (p == NULL)
        return;
    else{
        treeView(p->left);
        printf("%d\n", p->key);
        treeView(p->right);
    }
}

int main(void){

    treeInsert (8);
    treeInsert (2);
    treeInsert (8);
    treeInsert (7);
    treeInsert (5);
    treeInsert (4);
    treeDelete(2);
    treeView (root);
    return 0;
}