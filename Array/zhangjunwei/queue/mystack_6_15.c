#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define DATA int
#define QUEUE_SIZE 30
typedef struct {
    DATA *items;
    int head;
    int tail;
} Queue;

Queue *createQueue();

void enqueue(Queue *queue, DATA value);

void dequeue(Queue *queue, DATA *val);

//队尾元素出队
void dequeue_tail(Queue *queue, DATA *val);
//获取队尾元素
DATA queue_tail_element(Queue *queue);

bool isEmpty(Queue *queue);

bool isFull(Queue *queue);

void destoryQueue(Queue *queue);

Queue *createQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    if (queue != NULL) {
        queue->items = (DATA *) malloc(sizeof(DATA) * (QUEUE_SIZE));
        if (queue->items != NULL) {
            //循环数组  数组最大使用容量为QUEUE_SIZE-1  有一个空的不用 以用于判断 队列是否为空或为满
            queue->head = 1;
            queue->tail = 0;
            return queue;
        }
        free(queue);
    }
    return NULL;

}

void enqueue(Queue *queue, DATA value) {
    if (!isFull(queue)) {
        queue->tail = (queue->tail + 1) % QUEUE_SIZE;
        queue->items[queue->tail] = value;
    }
}

void dequeue(Queue *queue, DATA *val) {
    if (!isEmpty(queue)) {
        *val = queue->items[queue->head];
        queue->head = (queue->head + 1) % QUEUE_SIZE;
    }
}

void dequeue_tail(Queue *queue, DATA *val) {
    if (!isEmpty(queue)) {
        *val = queue->items[queue->tail];
        queue->tail = (queue->tail - 1) % QUEUE_SIZE;
    }
}

DATA queue_tail_element(Queue *queue) {
    return queue->items[queue->tail];
}

//
bool isEmpty(Queue *queue) {
    if ((queue->tail + 1) % QUEUE_SIZE == queue->head)
        return true;
    return false;
}

bool isFull(Queue *queue) {
    if ((queue->tail + 2) % QUEUE_SIZE == queue->head)
        return true;
    return false;
}

void destoryQueue(Queue *queue) {
    free(queue->items);
    free(queue);
}

typedef struct {
    Queue *queue;
} MyStack;

/** Initialize your data structure here. */

MyStack *myStackCreate() {
    MyStack *stack = (MyStack *) malloc(sizeof(MyStack));
    stack->queue = createQueue();
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack *obj, int x) {
    enqueue(obj->queue, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack *obj) {
    int res;
    dequeue_tail(obj->queue, &res);
    return res;
}

/** Get the top element. */
int myStackTop(MyStack *obj) {
    return queue_tail_element(obj->queue);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack *obj) {
    return isEmpty(obj->queue);
}

void myStackFree(MyStack *obj) {
    destoryQueue(obj->queue);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/