//
// Created by 刘畅 on 2020/6/20.
//

#include "day18.h"
#include <iostream>

#define MAXSIZE 20

typedef struct MyQueue {
    int maxsize;
    int rear;
    int front;
    int data[MAXSIZE];
} MaxQueue;

MaxQueue *maxQueueCreate();

bool isQueueFull(MaxQueue *obj);

bool isQueueEmpty(MaxQueue *obj);

int maxQueueMax_value(MaxQueue *obj);

void maxQueuePush_back(MaxQueue *obj, int data);

void maxQueuePop_front(MaxQueue *obj);

MaxQueue *maxQueueCreate() {
    MaxQueue *maxQueue = (MaxQueue *) malloc(sizeof(MyQueue));
    maxQueue->front = maxQueue->rear = 0;
    maxQueue->maxsize = 0;
    return maxQueue;
}

bool isQueueFull(MaxQueue *obj) {
    return obj->rear = MAXSIZE;
}

bool isQueueEmpty(MaxQueue *obj) {
    return obj->rear == obj->front;
}

int maxQueueMax_value(MaxQueue *obj) {
    return obj->maxsize;
}

void maxQueuePush_back(MaxQueue *obj, int data) {
    if (obj->rear >= MAXSIZE) {
        return;
    }
    if (data > obj->maxsize) {
        obj->maxsize = data;
    }
    obj->data[obj->rear] = data;
    obj->rear++;
}

void maxQueuePop_front(MaxQueue *obj) {
//    obj->data[obj->front] = obj->data[obj->front+1];
    int num = obj->data[obj->front];
    obj->front = (obj->front) + 1;
    if (num >= obj->maxsize) {
        obj->maxsize = 0;
        for (int i = obj->front; i < obj->rear; ++i) {
            if (obj->data[i]>obj->maxsize){
                obj->maxsize = obj->data[i];
            }
        }
    }

}

int main() {
    MaxQueue *maxQueue = maxQueueCreate();
    maxQueuePush_back(maxQueue, 9);
    maxQueuePush_back(maxQueue, 2);
    maxQueuePush_back(maxQueue, 3);
    maxQueuePush_back(maxQueue, 4);
    maxQueuePush_back(maxQueue, 5);
    maxQueuePush_back(maxQueue, 6);
    maxQueuePush_back(maxQueue, 7);
    maxQueuePush_back(maxQueue, 8);
    maxQueuePush_back(maxQueue, 1);
//    for (int i = 0; i <maxQueue->rear ; ++i) {
//        printf("%d\n",maxQueue->data[i]);
//    }
    maxQueuePop_front(maxQueue);
    for (int j = maxQueue->front; j < maxQueue->rear; ++j) {
        printf("%d\n", maxQueue->data[j]);
    }
    printf("=====%d\n======",maxQueueMax_value(maxQueue));
}
