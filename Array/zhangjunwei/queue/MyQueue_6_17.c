
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 20
typedef struct {
    int *enqueue;
    int *dequeue;
    int size;
} MyQueue;

/** Initialize your data structure here. */
bool myQueueEmpty(MyQueue *obj);

MyQueue *myQueueCreate() {
    MyQueue *stack = (MyQueue *) malloc(sizeof(MyQueue));
    if (NULL != stack) {
//        stack->enqueue = (int *) malloc(sizeof(int) * STACK_SIZE);
        stack->enqueue = (int *) calloc(STACK_SIZE, sizeof(int));
        stack->dequeue = (int *) calloc(STACK_SIZE, sizeof(int));
        stack->size = 0;
        if (NULL == stack->enqueue) {
            free(stack->enqueue);
            free(stack->dequeue);
            stack->enqueue = NULL;
            stack->dequeue = NULL;
            free(stack);
        }
    }
    return stack;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue *obj, int x) {
    if (obj->size < STACK_SIZE)
        obj->enqueue[obj->size++] = x;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue *obj) {
    int res = -1;
    if (myQueueEmpty(obj))return res;

    int i = 0;
    int j = obj->size;
    while (j >= 0) {
        obj->dequeue[i++] = obj->enqueue[j];
        obj->enqueue[j--] = 0;
    }
    res = obj->dequeue[obj->size];
    obj->dequeue[obj->size--] = 0;

    i=0;
    j = obj->size;
    while (j >= 0) {
        obj->enqueue[i++] = obj->dequeue[j];
        obj->dequeue[j--] = 0;
    }
    return res;
}

/** Get the front element. */
int myQueuePeek(MyQueue *obj) {
    int res = -1;
    if (myQueueEmpty(obj))return res;
    int i = 0;
    int j = obj->size;
    while (j >= 0) {
        obj->dequeue[i++] = obj->enqueue[j--];
    }
    res = obj->dequeue[obj->size];

    j = obj->size;
    while (j >= 0) {
        obj->dequeue[j--] = 0;
    }

    return res;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue *obj) {
    return NULL == obj || obj->size == 0;
}

void myQueueFree(MyQueue *obj) {
    if (NULL != obj) {
        free(obj->enqueue);
        free(obj->dequeue);
        obj->enqueue = NULL;
        obj->dequeue = NULL;
        free(obj);
        obj = NULL;
    }
}

int main() {
    MyQueue *obj = myQueueCreate();
    myQueuePush(obj, 1);
    myQueuePush(obj, 2);
    int param_2 = myQueuePop(obj);
    int param_3 = myQueuePeek(obj);
    bool param_4 = myQueueEmpty(obj);
    myQueueFree(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/
