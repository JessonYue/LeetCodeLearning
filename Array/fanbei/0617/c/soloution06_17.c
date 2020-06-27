#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define QUEUE_MAXSIZE  20
#define STACK_MAXSIZE  10

typedef struct {
    int *stack1;
    int *stack2;
    int stack1Length;
    int stack2Length;
} MyQueue;

/**
 *初始化数据结构
 */
MyQueue *myQueueCreate() {
    MyQueue *myQueue = malloc(sizeof(MyQueue));
    myQueue->stack1 = malloc(sizeof(int) * STACK_MAXSIZE);
    myQueue->stack2 = malloc(sizeof(int) * STACK_MAXSIZE);
    myQueue->stack1Length = 0;
    myQueue->stack2Length = 0;
    return myQueue;
}

void myQueuePush(MyQueue *obj, int x) {
    if ((obj->stack1Length + obj->stack2Length) > QUEUE_MAXSIZE) {
        return;
    }
    obj->stack1[obj->stack1Length++] = x;
}

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