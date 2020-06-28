
#include <stdio.h>
#include <stdlib.h>


#define EMPTY 0
#define EQUAL 1
#define BIGGER 2
#define SMALLER 3


/* 数据结构定义 */
typedef struct node{
    int key;
    struct node *left;
    struct node *right;
}NODE;

/* 树的建立与初始化 */
NODE *root = NULL;

//比较；目标值，节点值
int keyComp (int key, int cur_key);
//搜索；root作为搜索开始
NODE * treeSearch (int key);
//insert
NODE * treeInsert (int key);
//delete
int treeDelete (int key);
//找到右子树部分中的最小值
NODE * treeDeleteMin (NODE **p);
//中序
void treeView (NODE *p);

/* 主函数 */
int main()
{
    treeInsert (6);
    treeInsert (3);
    treeInsert (8);
    treeInsert (2);
    treeInsert (5);
    treeInsert (9);

    treeDelete(2);
//    treeDeleteMin(&root);
    treeView (root);

    return 0;
}


int keyComp (int key, int cur_key)
{
    if (key == cur_key)
        return EQUAL;
    else if (key > cur_key)
        return BIGGER;
    else return SMALLER;
}


NODE * treeSearch (int key)
{
    NODE * p = root;
    int flag;

    while (p != NULL){
        flag = keyComp(key, p->key);

        if (flag == EQUAL)
            return p;
        else if (flag == BIGGER)
            p = p->right;
        else        /* flag == SMALLER */
            p = p->left;
    }
    return NULL;        /* 没有该元素 */
}


NODE * treeInsert (int key)
{
    NODE **p = &root, *newNode;
    int flag;

    /* 搜索插入位置 */
    while ((*p) != NULL){ //*P 才是子节点 P是父节点

        flag = keyComp(key, (*p)->key);

        if(flag == EQUAL)       /* 已经有相同的key存在 */
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


int treeDelete (int key)
{
    NODE **p = &root, *x;
    int flag;
    while((*p) != NULL){
        flag = keyComp(key, (*p)->key);
        x = *p;
        if (flag == EQUAL){
            /* 没有孩子 */
            if ((x->right == NULL) && (x->right == NULL))
                *p = NULL;
                /* 有一个孩子 */
            else if (x->right == NULL)
                *p = x->left;
            else if (x->left == NULL)
                *p = x->right;
                /* 有两个孩子 */
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

/***
 * 删除右子树中的最小值
 * @param p
 * @return
 */
NODE *treeDeleteMin(NODE **p)
{
    NODE *x; //中间变量
    while ((*p)->left != NULL)
        p = &((*p)->left);
    x = *p;
    *p = x->right;

    return x;
}
/***
 * 左-->根-->右  中序遍历
 * @param p
 */
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