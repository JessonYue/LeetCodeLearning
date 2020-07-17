//
// Created by Vashon on 2020/7/16.
//

#ifndef C_BINARY_TREE_H
#define C_BINARY_TREE_H

typedef struct btree {
    int val;
    struct btree *lchild;
    struct btree *rchild;
} BTNode;

// 创建二叉树
void create_btree(BTNode **btree, char *str);

// 查找节点
BTNode * find_node(BTNode *btree, int x);

// 求树的高度
int btree_depth(BTNode *btree);

// 输出二叉树
void display_btree(BTNode *btree);

// 销毁二叉树
void destroy_btree(BTNode *btree);

#endif //C_BINARY_TREE_H
