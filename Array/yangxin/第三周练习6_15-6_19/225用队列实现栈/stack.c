//
// Created by 12 on 2020/6/15.
//
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct tagLinkNode{
    int val;
    struct Node *next;
} Node;

typedef struct {
    struct Node *head;
    struct Node *tail;
} MyStack;

/** Initialize your data structure here. */

MyStack *myStackCreate() {
    MyStack *stack = malloc(sizeof(MyStack));
    stack->tail = NULL;
    stack->head = NULL;
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack *obj, int x) {
    Node *node = malloc(sizeof(Node));
    node->val = x;
    node->next = NULL;
    if (obj->tail != NULL) {
        Node *tmp = obj->tail;
        tmp->next = node;
    }
    obj->tail = node;
    if (obj->head == NULL) {
        obj->head = obj->tail;
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack *obj) {
    if (obj->head == obj->tail) {
        Node *node = obj->head;
        int tmp = node->val;
        node->next = NULL;
        free(node);
        obj->head = NULL;
        obj->tail = NULL;
        return tmp;
    }

    Node *node = obj->head;
    while (node->next != obj->tail) {
        node = node->next;
    }
    obj->tail = node;
    node = node->next;
    int tmp = node->val;
    node->next = NULL;
    free(node);
    //释放后指向一定要设置为NUll，不然就是野指针，不为null，所以null失去意义
    Node *node2 = obj->tail;
    node2->next = NULL;

    return tmp;
}

/** Get the top element. */
int myStackTop(MyStack *obj) {
    Node *node = obj->tail;
    return node->val;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack *obj) {
    return obj->head == obj->tail && obj->head == NULL;
}

void myStackFree(MyStack *obj) {
    if (obj == NULL) {
        return;
    }
    Node *tmp = obj->head;
    //已经把每个节点都释放，不需要再去释放head和tail，去释放反而会报错
    while (tmp != NULL) {
        Node *next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(obj);
}

void main() {
    MyStack *myStack = myStackCreate();
    myStackPush(myStack, 1);
    myStackPush(myStack, 2);
    printf("%d", myStackTop(myStack));
    printf("%d", myStackPop(myStack));
//    printf("%d", myStackPop(myStack));
    printf("%d", myStackEmpty(myStack));
    myStackFree(myStack);
    return;
}