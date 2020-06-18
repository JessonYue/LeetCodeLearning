//
// Created by Vashon on 2020/6/18.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list_node.h"

// 队列的最大值，LeetCode面试题59-II
void homework_014_59(void) {
    MaxQueue *maxQueueCreate();
    int maxQueueMax_value(MaxQueue *obj);
    void maxQueuePush_back(MaxQueue *obj, int value);
    int maxQueuePop_front(MaxQueue *obj);
    void maxQueueFree(MaxQueue *obj);

    MaxQueue *obj = maxQueueCreate();
    int param_1 = maxQueueMax_value(obj);
    maxQueuePush_back(obj, 99);
    int param_3 = maxQueuePop_front(obj);
    printf("param_1:%d, param_3:%d\n", param_1, param_3);
    maxQueueFree(obj);
}

MaxQueue *maxQueueCreate() {
    MaxQueue *maxQueue = malloc(sizeof(MaxQueue));
    memset(maxQueue->data, 0, MAX_ARRAY_SIZE); // 初始化队列
    maxQueue->front = maxQueue->rear = -1;          // 队头与队尾
    maxQueue->maxValue = -1;                        // 最大值
    return maxQueue;
}

int maxQueueMax_value(MaxQueue *obj) {
    if (!obj || obj->front == -1)
        return -1;
    int start = obj->front;
    int end = (obj->rear + 1) % MAX_ARRAY_SIZE;
    int maxValue = -1;
    while (start != end) {
        if (obj->data[start] > maxValue)
            maxValue = obj->data[start];
        start = ((start + 1) % MAX_ARRAY_SIZE);
    }
    obj->maxValue = maxValue;
    return maxValue;
}

void maxQueuePush_back(MaxQueue *obj, int value) {
    if (!obj)
        return;
    int end = (obj->rear + 1) % MAX_ARRAY_SIZE;
    if (end == obj->front)  // 队满都直接返回
        return;
    if (obj->front == obj->rear && obj->front == -1) {    // 队空
        obj->front++;
        obj->rear++;
        obj->data[obj->front] = value;
    } else {
        obj->rear = end;
        obj->data[end] = value;
    }
}

int maxQueuePop_front(MaxQueue *obj) {
    if (!obj || obj->front == -1)
        return -1;
    int ele = obj->data[obj->front++];
    if (obj->front > obj->rear)  // 队空
        obj->front = obj->rear = -1;
    return ele;
}

void maxQueueFree(MaxQueue *obj) {
    if (!obj)
        return;
    free(obj);
    obj = NULL;
}