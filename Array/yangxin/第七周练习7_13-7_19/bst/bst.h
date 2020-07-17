//
// Created by 12 on 2020/6/28.
//

#ifndef LEETCODESTUDY_BST_H
#define LEETCODESTUDY_BST_H

typedef struct Node{
    int val;
    struct Node* left;
    struct Node* right;
}Node ;

typedef struct BsTree{
    Node* root;
}BsTree;

BsTree* createBsTree();
int addNode(BsTree* bst, int val);
Node* findNode(BsTree* bst, int val);
int upDataNode(BsTree* bst, int oldVal ,int newVal);
int deleteNode(BsTree* bst, int val);

#endif //LEETCODESTUDY_BST_H
