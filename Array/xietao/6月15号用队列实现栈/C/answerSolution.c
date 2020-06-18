//
// Created by 谢涛 on 2020/6/3.
//

#include "answerSolution.h"

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct QNode{
    struct QNode* next;
    DataType data;

}QNode;
//队列的结构
typedef struct Queue{
    QNode* front;//前
    QNode* rear;//后

}Queue;
//初始化队列
void QueueInit(Queue* q){
    q->front = q->rear = NULL;
}

// 队尾入队列
void QueuePush(Queue* q, DataType data){
    QNode* node = (QNode*)malloc(sizeof(QNode));
    node->data = data;
    node->next = NULL;
    if(q->rear){
        q->rear->next = node;
        q->rear = node;
    }else{
        q->front = q->rear = node;
    }
}
//队首出队列
void QueuePop(Queue* q){
    if(q->front->next == NULL){
        free(q->front);
        q->front = q->rear = NULL;
    }else{
        QNode* next = q->front->next;
        free(q->front);
        q->front = next;
    }
}
// 获取队列头部元素
DataType QueueFront(Queue* q){
    return q->front->data;
}
// 获取队列队尾元素
DataType QueueBack(Queue* q){
    return q->rear->data;
}
// 获取队列中有效元素个数
int QueueSize(Queue* q){
    QNode* curr = q->front;
    int count = 0;
    while(curr){
        count++;
        curr = curr->next;
    }
    return count;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue* q){
    return q->front ? 0 : 1;
}
// 销毁队列
void QueueDestroy(Queue* q){
    QNode* curr = q->front;
    while(curr){
        QNode* next = curr->next;
        free(curr);
        curr = next;
    }
    q->front = q->rear = NULL;
}
typedef struct {
    Queue q1;
    Queue q2;

} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    QueueInit(&stack->q1);
    QueueInit(&stack->q2);
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if(QueueEmpty(&obj->q1) == 0){
        QueuePush(&obj->q1, x);
    }else{
        QueuePush(&obj->q2, x);
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    Queue* emptyq = &obj->q2, *noemptyq = &obj->q1;
    DataType target;
    if(QueueEmpty(&obj->q1)){
        emptyq = &obj->q1;
        noemptyq = &obj->q2;
    }

    while(QueueSize(noemptyq) > 1){
        QueuePush(emptyq,QueueFront(noemptyq));
        QueuePop(noemptyq);
    }

    target = QueueFront(noemptyq);
    QueuePop(noemptyq);
    return target;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {//获取栈顶元素
    Queue* noemptyq = &obj->q1;
    if(QueueEmpty(&obj->q1) != 0){
        noemptyq = &obj->q2;
    }
    return QueueBack(noemptyq);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2)){
        return true;
    }else{
        return false;
    }
}

void myStackFree(MyStack* obj) {
    QueueDestroy(&obj->q1);
    QueueDestroy(&obj->q2);
    free(obj);
    obj = NULL;
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