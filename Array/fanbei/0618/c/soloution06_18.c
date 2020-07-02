#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct {
    int val;
    struct QueueNode *next;
    struct QueueNode *pre;
} QueueNode;

typedef struct {
    QueueNode *head;
    QueueNode *tail;
    int size;
    QueueNode *head2;
    QueueNode *tail2;
    int size2;
} MaxQueue;

/**
 *初始化数据结构
 */
MaxQueue *maxQueueCreate() {
    MaxQueue *maxQueue = malloc(sizeof(MaxQueue));
    maxQueue->head = malloc(sizeof(QueueNode));
    maxQueue->tail = malloc(sizeof(QueueNode));
    maxQueue->head2 = malloc(sizeof(QueueNode));
    maxQueue->tail2 = malloc(sizeof(QueueNode));
    maxQueue->head->next = maxQueue->tail;
    maxQueue->head->val = 0;
    maxQueue->head->pre = NULL;
    maxQueue->tail->next = NULL;
    maxQueue->tail->val = 0;
    maxQueue->tail->pre = maxQueue->head;
    maxQueue->size = 0;
    maxQueue->head2->next = maxQueue->tail2;
    maxQueue->head2->val = 0;
    maxQueue->head2->pre = NULL;
    maxQueue->tail2->next = NULL;
    maxQueue->tail2->val = 0;
    maxQueue->tail2->pre = maxQueue->head2;
    maxQueue->size2 = 0;
    return maxQueue;
}

int maxQueueMax_value(MaxQueue *obj) {
    if (obj->size2 == 0) {
        return -1;
    }
    QueueNode *node = obj->head2->next;
    return node->val;
}

void maxQueuePush_back(MaxQueue *obj, int value) {
    QueueNode *node = malloc(sizeof(QueueNode));
    node->val = value;
    node->next = obj->tail;
    node->pre = obj->tail->pre;
    QueueNode *pre = obj->tail->pre;
    pre->next = node;
    obj->tail->pre = node;
    obj->size++;
    QueueNode *last = obj->tail2->pre;
    while (obj->size2 > 0 && last->val < value) {
        QueueNode *pre = last->pre;
        pre->next = obj->tail2;
        obj->tail2->pre = pre;
        obj->size2--;
        free(last);
        last = pre;
    }
    QueueNode *node2 = malloc(sizeof(QueueNode));
    node2->val = value;
    node2->next = obj->tail2;
    node2->pre = obj->tail2->pre;
    QueueNode *pre2 = obj->tail2->pre;
    pre2->next = node2;
    obj->tail2->pre = node2;
    obj->size2++;
}

int maxQueuePop_front(MaxQueue *obj) {
    if (obj->size == 0) {
        return -1;
    }
    QueueNode *first = obj->head->next;
    obj->head->next = first->next;
    QueueNode *next = first->next;
    next->pre = obj->head;
    int result = first->val;
    free(first);
    obj->size--;
    QueueNode *first2 = obj->head2->next;
    if (result == first2->val) {
        obj->head2->next = first2->next;
        QueueNode *next2 = first2->next;
        next2->pre = obj->head2;
        free(first2);
        obj->size2--;
    }
    return result;
}

void maxQueueFree(MaxQueue *obj) {
    while (obj->head->next != obj->tail) {
        QueueNode *first = obj->head->next;
        QueueNode *next = first->next;
        obj->head->next = next;
        next->pre = obj->head;
        free(first);
    }
    while (obj->head2->next != obj->tail2) {
        QueueNode *first = obj->head2->next;
        QueueNode *next = first->next;
        obj->head2->next = next;
        next->pre = obj->head2;
        free(first);
    }
    free(obj->head);
    free(obj->tail);
    free(obj->head2);
    free(obj->tail2);
    free(obj);
}

//void main() {
//    MaxQueue *maxQueue = maxQueueCreate();
//    printf("%d", maxQueuePop_front(maxQueue));
//    printf("%d", maxQueuePop_front(maxQueue));
//    printf("%d", maxQueuePop_front(maxQueue));
//    printf("%d", maxQueuePop_front(maxQueue));
//    maxQueuePush_back(maxQueue, 15);
//    printf("%d", maxQueueMax_value(maxQueue));
//    maxQueuePush_back(maxQueue, 9);
//    printf("%d", maxQueueMax_value(maxQueue));
//    maxQueueFree(maxQueue);
//    return;
//}

