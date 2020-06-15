//
// Created by 吴超 on 2020/6/15.
//
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
}Node;
typedef struct {
    Node* head;
    Node* tail;
    int value;
} MyQueue;
void myQueueCreate(MyQueue* queue);
void enqueue(MyQueue* queue,int value);
int dequeue(MyQueue* queue);
int size(MyQueue* queue);
int isEmpty(MyQueue* queue);
typedef struct {
    MyQueue* queue;
    MyQueue* tempQueue;
    int top;
} MyStack;
void myStackPush(MyStack* obj, int x);
int myStackPop(MyStack* obj);
MyStack* myStackCreate();

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* myStack = malloc(sizeof(MyStack));
    myStack->queue = malloc(sizeof(MyQueue));
    myStack->tempQueue = malloc(sizeof(MyQueue));
    myQueueCreate(myStack->queue);
    myQueueCreate(myStack->tempQueue);
    return myStack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    enqueue(obj->queue,x);
    obj->top = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if(isEmpty(obj->queue)){
        return -1;
    } else {
        int popElement;
        if(size(obj->queue)==1){
            return dequeue(obj->queue);
        } else {
            while (size(obj->queue)>1){
                enqueue(obj->tempQueue,dequeue(obj->queue));
            }
            int popElement = dequeue(obj->queue);
            while (!isEmpty(obj->tempQueue)){
                obj->top = dequeue(obj->tempQueue);
                enqueue(obj->queue,obj->top);
            }
            return popElement;
        }
    }
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->top;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return isEmpty(obj->queue);
}

void myStackFree(MyStack* obj) {
    obj->top = -1;
    free(obj->queue);
    free(obj->tempQueue);
    free(obj);
}

void myQueueCreate(MyQueue* queue){
    Node* node = malloc(sizeof(Node));
    Node* node2 = malloc(sizeof(Node));
    node->value = -1;
    node2->value = -1;
    node2->next = NULL;
    node->next = node2;
    queue->head = node;
    queue->tail = node2;
    queue->value = 0;
}

void enqueue(MyQueue* queue,int value){
    Node* node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    queue->tail->next = node;
    queue->tail = node;
    queue->value++;
    if(size(queue)==1){
        queue->head->next = queue->tail;
    }
}

int dequeue(MyQueue* queue){
    if(!isEmpty(queue)){
        Node* temp = queue->head->next;
        queue->head->next = temp->next;
        queue->value--;
        temp->next = NULL;
        int value = temp->value;
        return value;
    }
    return -1;
}

int isEmpty(MyQueue* queue){
    return !size(queue);
}

int size(MyQueue* queue){
    return queue->value;
}



