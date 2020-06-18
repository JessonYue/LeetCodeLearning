//
// Created by Vashon on 2020/6/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "list_node.h"

// 化栈为队，LeetCode面试题03.04
void homework_013_0304(void) {
    MyQueue *myQueueCreate();
    void myQueuePush(MyQueue *, int);
    int myQueuePop(MyQueue *obj);
    int myQueuePeek(MyQueue *obj);
    int myQueueEmpty(MyQueue *obj);
    void myQueueFree(MyQueue *obj);

    MyQueue *queue = myQueueCreate();
    myQueuePush(queue, 3);
    int param_2 = myQueuePop(queue);
    int param_3 = myQueuePeek(queue);
    int param_4 = myQueueEmpty(queue);
    printf("param_2:%d, param_3:%d, param_4:%d\n", param_2, param_3, param_4);
    myQueueFree(queue);
}

/** Initialize your data structure here. */
MyQueue *myQueueCreate() {
    MyQueue *queue = malloc(sizeof(MyQueue));
    queue->stack = NULL;
    queue->top = -1;
    return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue *obj, int x) {
    // 队列先进先出的特性，所以尾插法建栈
    if (!obj)
        return;
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->val = x;
    if (!obj->stack)    // 如果栈为空
        obj->stack = node;
    else {
        Node *temp = obj->stack;
        while (temp->next)
            temp = temp->next;
        temp->next = node;
    }
    obj->top++;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue *obj) {
    int ele = 0;
    if (!obj || obj->top == -1)
        return ele;
    Node *top = obj->stack;
    ele = top->val;
    obj->stack = top->next;
    obj->top--;
    free(top);
    return ele;
}

/** Get the front element. */
int myQueuePeek(MyQueue *obj) {
    int ele = 0;
    if (!obj || obj->top == -1)
        return ele;
    ele = obj->stack->val;
    return ele;
}

/** Returns whether the queue is empty. */
int myQueueEmpty(MyQueue *obj) {
    if (!obj || obj->top == -1)
        return 1;
    return 0;
}

void myQueueFree(MyQueue *obj) {
    if (!obj || obj->top == -1)
        return;
    Node *temp = obj->stack;
    while (temp) {
        obj->stack = temp->next;
        free(temp);
        temp = obj->stack;
    }
    free(obj);
}