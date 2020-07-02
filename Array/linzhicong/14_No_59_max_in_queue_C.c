#define MAX_SIZE 1000
typedef struct MyQueue {
    int* data[MAX_SIZE];
    int head;
    int tail;
} MyQueue;

typedef struct {
    struct MyQueue *fQueue;
    struct MyQueue *lQueue; // 用于保存最大值顺序的队列
} MaxQueue;


MaxQueue* maxQueueCreate() {
    MaxQueue* queue = (MaxQueue*)malloc(sizeof(MaxQueue));
    queue->fQueue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->lQueue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->fQueue->head = queue->fQueue->tail = 0;
    queue->lQueue->head = queue->lQueue->tail = 0;
    return queue;
}

int maxQueueMax_value(MaxQueue* obj) {
    if(obj && !isEmpty(obj->lQueue)) {
        return obj->lQueue->data[obj->lQueue->head];
    }
    return -1;
}

void maxQueuePush_back(MaxQueue* obj, int value) {
    if(!obj || isFull(obj->fQueue)) return;
    
    obj->fQueue->data[obj->fQueue->tail] = value;
    obj->fQueue->tail = (obj->fQueue->tail + 1) % MAX_SIZE;

    while(!isEmpty(obj->lQueue) && obj->lQueue->data[obj->lQueue->tail - 1] <= value) {
        obj->lQueue->data[obj->lQueue->tail] = 0;
        obj->lQueue->tail = getIndex(obj->lQueue->tail - 1);
    }
    if(isEmpty(obj->lQueue)) {
        if(obj->lQueue->data[getIndex(obj->lQueue->tail - 1)] > value) {
            obj->lQueue->tail = (obj->lQueue->tail + 1) % MAX_SIZE;
        }
        obj->lQueue->data[obj->lQueue->tail] = value;
        obj->lQueue->tail = (obj->lQueue->tail + 1) % MAX_SIZE;
    } else {
        obj->lQueue->data[obj->lQueue->tail] = value;
        obj->lQueue->tail = (obj->lQueue->tail + 1) % MAX_SIZE;
    }
}

int maxQueuePop_front(MaxQueue* obj) {
    if(isEmpty(obj->fQueue)) return -1;
    int temp = obj->fQueue->data[obj->fQueue->head];
    obj->fQueue->data[obj->fQueue->head] = 0;
    obj->fQueue->head = (obj->fQueue->head + 1) % MAX_SIZE;

    if(temp == obj->lQueue->data[obj->lQueue->head]) {
        obj->lQueue->data[obj->lQueue->head] = 0;
        obj->lQueue->head = (obj->lQueue->head + 1) % MAX_SIZE;
    }
    return temp;
}

void maxQueueFree(MaxQueue* obj) {
    free(obj->fQueue);
    free(obj->lQueue);
    free(obj);
}

int isEmpty(MyQueue* myQueue) {
    if(myQueue->tail == myQueue->head) {
        return 1;
    }
    return 0;
}

int isFull(MyQueue* myQueue) {
    if((myQueue->tail + 1) % MAX_SIZE == myQueue->head) {
        return 1;
    }
    return 0;
}

int getIndex(int index) {
    return index < 0 ? MAX_SIZE - 1 : index;
}

/**
 * Your MaxQueue struct will be instantiated and called as such:
 * MaxQueue* obj = maxQueueCreate();
 * int param_1 = maxQueueMax_value(obj);
 
 * maxQueuePush_back(obj, value);
 
 * int param_3 = maxQueuePop_front(obj);
 
 * maxQueueFree(obj);
*/