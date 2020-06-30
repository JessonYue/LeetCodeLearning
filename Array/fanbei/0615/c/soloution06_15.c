#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct tagLinkNode {
    int val;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} MyStack;

/**
 *初始化数据结构
 */
MyStack *myStackCreate() {
    MyStack *stack = (MyStack *) malloc(sizeof(MyStack));
    stack->head = NULL;
    stack->tail = NULL;
    return stack;
}

void myStackPush(MyStack *obj, int x) {
    Node *node = (Node *) malloc(sizeof(Node));
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
    Node *node2 = obj->tail;
    node2->next = NULL;
    return tmp;
}

int myStackTop(MyStack *obj) {
    Node *node = obj->tail;
    return node->val;
}

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
    printf("%d", myStackEmpty(myStack));
    myStackFree(myStack);
    return;
}



