//
// Created by 丰雷 on 2020/7/3.
//

#include <stdio.h>
#include <assert.h>
#include <mm_malloc.h>

#define MAX_SIZE 10

typedef struct _RingBuffer {
    int Queue[MAX_SIZE];
    // 头指针
    int front;
    // 尾指针
    int rear;
} RingBuffer;

RingBuffer *initQueue();

int isEmpty(RingBuffer *buffer);

int isFull(RingBuffer *buffer);

int putVal(RingBuffer *buffer, int data);

int deleteVal(RingBuffer *buffer, int data);

void printBuffer(RingBuffer *buffer);


RingBuffer *initQueue() {
    RingBuffer *buffer = malloc(sizeof(RingBuffer));
    buffer->rear = buffer->front = 0;
    printf("RingBuffer init completed\n");
    return buffer;
}

int isEmpty(RingBuffer *buffer) {
    if (buffer->front == buffer->rear) {
        return 1;
    }
    return 0;
}

int isFull(RingBuffer *buffer) {
    assert(buffer);
    if ((buffer->rear + 1) % MAX_SIZE == buffer->front) {
        return 1;
    }
    return 0;
}

int deleteVal(RingBuffer *buffer, int data) {
    assert(buffer);
    int index = 0;
    while (buffer->Queue[index] != 0) {
        if (buffer->Queue[index] == data) {
            buffer->Queue[index] = 0;
            buffer->front = (buffer->front + 1) % MAX_SIZE;
            return data;
        }
        index++;
    }
    return -1;
}


int putVal(RingBuffer *buffer, int data) {
    assert(buffer);
    if (isFull(buffer) == 1) {
        buffer->front = (buffer->front + 1) % MAX_SIZE;
    }
    buffer->Queue[buffer->rear] = data;
    buffer->rear = (buffer->rear + 1) % MAX_SIZE;
    return 1;
}

void printBuffer(RingBuffer *buffer) {
    assert(buffer);
    if (isEmpty(buffer) == 1) return;
    int i = buffer->front;
    while (i != (buffer->rear)) {
        printf("%d   ", buffer->Queue[i]);
        i = (i + 1) % MAX_SIZE;

    }
    printf("\n");
}

int main() {
    RingBuffer *buffer = initQueue();
    for (int i = 1; i < 20; ++i) {
        putVal(buffer, i);
        printBuffer(buffer);
    }
    deleteVal(buffer, 15);
}