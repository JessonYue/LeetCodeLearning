#include <stdio.h>
#include <stdlib.h>
//
// Created by 吴超 on 2020/6/18.
//
typedef struct Node{
    int value;
    struct Node* next;
} Node;

Node* createNode(int value);
Node* createNode(int value){
    Node* node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}
typedef struct {
    Node* head;
    Node* tail;
    int max;
} MaxQueue;

int maxQueueEmpty(MaxQueue* maxQueue);
int maxQueueEmpty(MaxQueue* maxQueue){
    return maxQueue->head->next == NULL;
}


MaxQueue *maxQueueCreate() {
    MaxQueue *maxQueue = malloc(sizeof(MaxQueue));
    maxQueue->head = createNode(-1);
    maxQueue->tail = maxQueue->head;
    maxQueue->max = -1;
    return maxQueue;
}

int maxQueueMax_value(MaxQueue *obj) {
    return obj->max;
}

void maxQueuePush_back(MaxQueue *obj, int value) {
    obj->tail->next = createNode(value);
    obj->tail = obj->tail->next;
    if (value >= obj->max) {
        obj->max = value;
    }
}

int maxQueuePop_front(MaxQueue *obj) {
    if (maxQueueEmpty(obj)) {
        return -1;
    }
    Node *head = obj->head;
    obj->head = obj->head->next;
    if(obj->head->value==obj->max){
        obj->max = -1;
        Node* maxHead = obj->head->next;
        while (maxHead!=NULL){
            if(maxHead->value>obj->max){
                obj->max = maxHead->value;
            }
            maxHead = maxHead->next;
        }
    }
    head->next = NULL;
    free(head);
    return obj->head->value;
}

void maxQueueFree(MaxQueue *obj) {
    free(obj);
}

