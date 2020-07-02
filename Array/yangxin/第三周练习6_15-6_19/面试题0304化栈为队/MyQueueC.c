#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

/**
 * 面试题 03.04. 化栈为队
 * 实现一个MyQueue类，该类用两个栈来实现一个队列。
 */
//数组指针最大20
#define QUEUE_MAXSIZE  20
#define STACK_MAXSIZE  10

typedef struct {
    int *stack1;
    int *stack2;
    int stack1Length;
    int stack2Length;
} MyQueue;

/** Initialize your data structure here. */

MyQueue *myQueueCreate() {
    MyQueue *myQueue = malloc(sizeof(MyQueue));
    myQueue->stack1 = malloc(sizeof(int) * STACK_MAXSIZE);
    myQueue->stack2 = malloc(sizeof(int) * STACK_MAXSIZE);
    myQueue->stack1Length = 0;
    myQueue->stack2Length = 0;
    return myQueue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue *obj, int x) {
    if ((obj->stack1Length + obj->stack2Length) > QUEUE_MAXSIZE) {
        return;
    }
    obj->stack1[obj->stack1Length++] = x;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue *obj) {
    if (obj->stack2Length == 0) {
        while (obj->stack1Length > 0) {
            obj->stack2[obj->stack2Length++] = obj->stack1[obj->stack1Length - 1];
            obj->stack1[obj->stack1Length - 1] = 0;
            obj->stack1Length--;
        }
    }

    int result = obj->stack2[obj->stack2Length - 1];
    obj->stack2[obj->stack2Length - 1] = 0;
    obj->stack2Length--;
    return result;
}

/** Get the front element. */
int myQueuePeek(MyQueue *obj) {
    if (obj->stack2Length == 0) {
        while (obj->stack1Length > 0) {
            obj->stack2[obj->stack2Length++] = obj->stack1[obj->stack1Length - 1];
            obj->stack1[obj->stack1Length - 1] = 0;
            obj->stack1Length--;
        }
    }

    return obj->stack2[obj->stack2Length - 1];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue *obj) {
    return obj->stack1Length == 0 && obj->stack2Length == 0;
}

void myQueueFree(MyQueue *obj) {
    free(obj->stack1);
    free(obj->stack2);
    obj->stack1Length = 0;
    obj->stack2Length = 0;
    free(obj);
}