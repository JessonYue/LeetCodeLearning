#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int capacity;
    int *items;
    int head;
    int tail;
    int maxItem;
} MaxQueue;

#define MAXQUEUE_CAPACITY 10001

MaxQueue *maxQueueCreate() {
    MaxQueue *maxQueue = (MaxQueue *) malloc(sizeof(MaxQueue));
    if (NULL != maxQueue) {
        maxQueue->items = (int *) calloc(MAXQUEUE_CAPACITY, sizeof(int));
        if (NULL != maxQueue->items) {
            maxQueue->capacity = MAXQUEUE_CAPACITY;
            maxQueue->head = maxQueue->tail = 0;
            maxQueue->maxItem = -1;
        } else {
            free(maxQueue);
            maxQueue = NULL;
        }
    }
    return maxQueue;
}

bool maxQueue_isEmpty(MaxQueue *obj) {
    return obj->head == obj->tail;
}

bool maxQueue_isFull(MaxQueue *obj) {
    return (obj->tail + 1) % obj->capacity == obj->head;
}

int maxQueueMax_value(MaxQueue *obj) {
    if (!maxQueue_isEmpty(obj)) {
        return obj->maxItem;
    }
    return -1;
}

void maxQueuePush_back(MaxQueue *obj, int value) {
    if (!maxQueue_isFull(obj)) {
        obj->items[obj->tail] = value;
        obj->tail = (obj->tail + 1) % obj->capacity;
        if (value > obj->maxItem)
            obj->maxItem = value;
    }
}
//int maxQueuePop_front(MaxQueue *obj) {
//    if (maxQueue_isEmpty(obj)){
//        obj->maxItem = -1;
//        return -1;
//    }
//    int res = obj->items[obj->head];
//    obj->head = (obj->head+1)%obj->capacity;
//    if (maxQueue_isEmpty(obj)){
//        obj->maxItem =-1;
//        return res;
//    }
//    if (obj->maxItem == res) {
//        obj->maxItem = -1;
//        for (int i = obj->head; (i + obj->capacity) % obj->capacity <= obj->tail; i++) {
//            if (obj->maxItem < obj->items[i])
//                obj->maxItem = obj->items[i];
//        }
//
//    }
//    if (obj->maxItem==res){
//        obj->maxItem = -1;
//        for (int i = obj->head; i <= obj->tail; i=(++i)%obj->capacity) {
//            if (obj->maxItem<obj->items[i])
//                obj->maxItem = obj->items[i];
//        }
//    }
//
//    return res;
//}
int maxQueuePop_front(MaxQueue *obj) {
    if (!maxQueue_isEmpty(obj)) {
        int res = obj->items[obj->head];
        obj->items[obj->head] = 0;
        obj->head = (obj->head + 1) % obj->capacity;
        if (maxQueue_isEmpty(obj)){
            obj->maxItem = -1;
            return res;
        }
        if (obj->maxItem == res) {
            obj->maxItem = -1;
            for (int i = obj->head;  i <= obj->tail; i=(++i)%obj->capacity) {
                if (obj->maxItem < obj->items[i])
                    obj->maxItem = obj->items[i];
            }

        }
        return res;
    }
    obj->maxItem = -1;
    return -1;
}

void maxQueueFree(MaxQueue *obj) {
    free(obj->items);
    obj->items = NULL;
//    obj->maxItem = -1;
//    obj->head = obj->tail = 0;
    free(obj);
    obj = NULL;
}
//void main(){
//    MaxQueue* obj = maxQueueCreate();
//    int param_1 = maxQueueMax_value(obj);
//
//    maxQueuePush_back(obj, 1);
//    maxQueuePush_back(obj, 2);
//
//    int param_3 = maxQueuePop_front(obj);
//
//    maxQueueFree(obj);
//}

/**
 * Your MaxQueue struct will be instantiated and called as such:
 * MaxQueue* obj = maxQueueCreate();
 * int param_1 = maxQueueMax_value(obj);

 * maxQueuePush_back(obj, value);

 * int param_3 = maxQueuePop_front(obj);

 * maxQueueFree(obj);
*/