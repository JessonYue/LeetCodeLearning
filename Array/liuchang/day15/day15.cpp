//
// Created by 刘畅 on 2020/6/18.
//
#include <iostream>
#include "day.h"
#include "stdio.h"
#define MAXSIZE 100

typedef struct Queue {
    int data[MAXSIZE];
    int front;
    int rear;

} StackQueue;

StackQueue *myStackCreate();

void myStackPush(StackQueue *queue, int data);

void myStackPop(StackQueue *queue);

int myStackTop(StackQueue *queue);

bool myStackEmpty(StackQueue *queue);

void myStackFree(StackQueue *queue);

int myStackIsFull(StackQueue *queue);

void printQueue(StackQueue *queue);

/** Initialize your data structure here. */

StackQueue *myStackCreate() {
    StackQueue *stack = (StackQueue *) malloc(sizeof(StackQueue));
    stack->front = 0;
    stack->rear = 0;
    return stack;
}

/** Push element x onto stack. */
void myStackPush(StackQueue *queue, int data) {

    queue->data[queue->rear] = data;
    queue->rear++;
}

/** Removes the element on top of the stack and returns that element. */
void myStackPop(StackQueue *queue) {

    queue->data[queue->rear] = queue->data[queue->rear-1];
    queue->rear--;
}

/** Get the top element. */
int myStackTop(StackQueue *queue) {
    if (myStackEmpty(queue)) {
        return -1;
    }
    return queue->data[queue->rear];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(StackQueue *queue) {
    return queue->front == queue->rear;
}

void myStackFree(StackQueue *queue) {
    free(queue);
}

void printQueue(StackQueue *queue) {
    for (int i = 0; i < queue->rear; ++i) {
        printf("%d\n", queue->data[i]);
    }
}

int main() {
    StackQueue *queue = myStackCreate();
    myStackPush(queue, 1);
    myStackPush(queue, 2);
    myStackPush(queue, 3);
    myStackPush(queue, 4);
    myStackPush(queue, 5);
    myStackPush(queue, 6);
    myStackPush(queue, 7);
    myStackPush(queue, 8);
    myStackPush(queue, 9);
    myStackPush(queue, 10);
//    printQueue(queue);
    myStackPop(queue);
    printQueue(queue);
}