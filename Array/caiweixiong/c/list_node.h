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
#endif //C_LIST_NODE_H
