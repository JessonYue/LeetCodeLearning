#include <stdbool.h>
#include <stdlib.h>
//
// Created by 吴超 on 2020/6/17.
//

typedef struct {
    int value;
    struct Node* next;
} Node;
Node* createNode(int x);
typedef struct {
    Node* head;
} MyStack;
MyStack* myStackCreate();
void myStackPush(MyStack* obj, int x);
int myStackPop(MyStack* obj);
int myStackTop(MyStack* obj);
bool myStackEmpty(MyStack* obj);

Node* createNode(int x){
    Node* node = malloc(sizeof(Node));
    node->value = x;
    node->next = NULL;
    return node;
}

MyStack* myStackCreate(){
    MyStack* myStack = malloc(sizeof(MyStack));
    myStack->head = createNode(-1);
    return myStack;
}

bool myStackEmpty(MyStack* obj){
    return obj->head->next == NULL;
}

void myStackPush(MyStack* obj, int x){
    Node* node = createNode(x);
    node->next = obj->head;
    obj->head = node;
}

int myStackPop(MyStack* obj){
    if(myStackEmpty(obj)){
        return -1;
    }
    int top = myStackTop(obj);
    obj->head = obj->head->next;
    return top;
}

int myStackTop(MyStack* obj){
    return obj->head->value;
}

typedef struct {
    MyStack * temp;
    MyStack * stack;
} MyQueue;
bool myQueueEmpty(MyQueue* obj);

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* myQueue = malloc(sizeof(MyQueue));
    myQueue->temp = myStackCreate();
    myQueue->stack = myStackCreate();
    return myQueue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    while(!myStackEmpty(obj->stack)){
        myStackPush(obj->temp,myStackPop(obj->stack));
    }
    myStackPush(obj->stack,x);
    while(!myStackEmpty(obj->temp)){
        myStackPush(obj->stack,myStackPop(obj->temp));
    }
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    return myStackPop(obj->stack);
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    return myStackTop(obj->stack);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return myStackEmpty(obj->stack);
}

void myQueueFree(MyQueue* obj) {
    free(obj->temp);
    free(obj->stack);
    free(obj);
}
