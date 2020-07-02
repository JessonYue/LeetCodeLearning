//
// Created by 谢涛 on 2020/6/3.
//

#include "answerSolution.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}Node;
Node* newNode(int val){
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = val;
    n->next = 0;
    return n;
}
void push(Node* head,int val){//入栈
    Node* n = newNode(val);
    n->next = head->next;
    head->next = n;
}
int pop(Node* head){//移除栈顶的元素
    Node * n = head->next;
    head->next = n->next;
    int result = n->val;
    free(n);
    return result;
}
int peek(Node* head){//获取栈底的元素
    Node* n = head->next;
    while(n->next != 0){
        n = n->next;
    }
    int result = n->val;
    return result;

}
void del(Node* head){
    while(head != 0){
        Node* n = head;
        head = head->next;
        free(n);
    }
}

typedef struct {
    Node* stackIn;
    Node* stackOut;
} MyQueue;

/** Initialize your data structure here. */
bool myQueueEmpty(MyQueue* obj);
MyQueue* myQueueCreate() {
    MyQueue * myq = (MyQueue*)malloc(sizeof(MyQueue));
    myq->stackIn = newNode(0);
    myq->stackOut = newNode(0);
    return myq;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    push(obj->stackIn,x);

}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {//移除顶部元素
    if(myQueueEmpty(obj))
        return -1;
    if(obj->stackOut->next==0){
        while(obj->stackIn->next != 0)
            push(obj->stackOut,pop(obj->stackIn));
    }
    return pop(obj->stackOut);

}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if(myQueueEmpty(obj)){
        return -1;
    }
    if(obj->stackOut->next==0)
        return(peek(obj->stackIn));
    return obj->stackOut->next->val;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if(obj->stackOut->next == 0 & obj->stackIn->next == 0)
        return true;
    return false;
}

void myQueueFree(MyQueue* obj) {
    del(obj->stackIn);
    del(obj->stackOut);
    free(obj);
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