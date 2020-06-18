//
// Created by Vashon on 2020/6/8.
//

#ifndef C_LIST_NODE_H
#define C_LIST_NODE_H

typedef struct ListNode {
    int val;
    struct ListNode *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} MyStack;

#endif //C_LIST_NODE_H
