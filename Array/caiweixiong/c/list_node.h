//
// Created by Vashon on 2020/6/8.
//

#ifndef C_LIST_NODE_H
#define C_LIST_NODE_H
#define MAX_ARRAY_SIZE 10000

typedef struct ListNode {
    int val;
    struct ListNode *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} MyStack;

typedef struct Stack {
    Node *stack;
    int top;
} MyQueue;

typedef struct {
    int data[MAX_ARRAY_SIZE];
    int maxValue;
    int front;
    int rear;
} MaxQueue;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
// 打印树的节点信息
void displayTree(struct TreeNode *tree);
// 销毁树
void destroyTree(struct TreeNode *tree);
#endif //C_LIST_NODE_H
