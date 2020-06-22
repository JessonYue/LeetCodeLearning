//
// Created by 崔继霖 on 2020/6/18.
//

#ifndef ALGO_C_LINKED_STACK_H
#define ALGO_C_LINKED_STACK_H

typedef int data;

#define TRUE 1
#define FALSE 0

typedef struct ListStackNode {
    data value;
    struct ListStackNode *next;
} ListStackNode;

typedef struct LinkedStack {
    struct ListStackNode *top;
    int length;
} Stack;

Stack *createStack();

ListStackNode *pop(Stack *stack);

ListStackNode *push(Stack *stack, data value);

void *printStack(Stack *stack);


void *release(Stack *stack);

int *isStackEmpty(Stack *stack);

void *test_stack();

#endif //ALGO_C_LINKED_STACK_H
