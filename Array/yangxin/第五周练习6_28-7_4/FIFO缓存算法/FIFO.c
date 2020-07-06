//
// Created by 12 on 2020/7/3.
// FIFO算法练习
//

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define ARRAY_SIZE 5

typedef struct Node {
    int data;
    struct Node *pre;
    struct Node *next;
} Node;

typedef struct FIFO {
    //使用rang数组实现
    int array[ARRAY_SIZE];
    int head;
    //尾用来做标记，不保存实际数据，实际数据应该是head到tail的前一个元素
    int tail;
} FIFO;

FIFO *createFIFO();

bool FIFOAddData(struct FIFO *fifo, int data);

bool FIFORemoveData(struct FIFO *fifo, int *r);

int FIFOSize(struct FIFO *fifo);

bool FIFOLastData(struct FIFO *fifo, int *r);

FIFO *createFIFO() {
    FIFO *fifo = calloc(1, sizeof(FIFO));
    return fifo;
}

bool FIFOAddData(struct FIFO *fifo, int data) {
    if (fifo == NULL) {
        return false;
    }

    int tmp = (fifo->tail + 1) % ARRAY_SIZE;

    if (tmp != fifo->head) {
        fifo->array[fifo->tail] = data;
        fifo->tail = tmp;
        return true;
    } else {
        int r;
        FIFORemoveData(fifo, &r);
        printf("remove=%d\n", r);
        return FIFOAddData(fifo, data);
    }
}

bool FIFORemoveData(struct FIFO *fifo, int *r) {
    if (fifo == NULL) {
        return false;
    }

    if (fifo->head == fifo->tail) {
        return false;
    } else {
        *r = fifo->array[fifo->head];
        fifo->head = (fifo->head + 1) % ARRAY_SIZE;
        return true;
    }
}

int FIFOSize(struct FIFO *fifo) {
    if (fifo->head == fifo->tail) {
        return 0;
    } else if (fifo->head > fifo->tail) {
        return fifo->tail - fifo->head + ARRAY_SIZE;
    } else {
        return fifo->tail - fifo->head;
    }
}

bool FIFOLastData(struct FIFO *fifo, int *r) {
    if (fifo->head == fifo->tail) {
        return false;
    }

    int tmp = fifo->tail - 1;
    if (tmp < 0) {
        tmp += ARRAY_SIZE;
    }
    *r = fifo->array[tmp];
    return true;
}


int main() {
    FIFO *fifo = createFIFO();
    printf("FIFOSize=%d\n", FIFOSize(fifo));
    FIFOAddData(fifo, 1);
    FIFOAddData(fifo, 2);
    FIFOAddData(fifo, 3);
    printf("FIFOSize=%d\n", FIFOSize(fifo));
    FIFOAddData(fifo, 4);
    printf("FIFOSize=%d\n", FIFOSize(fifo));
    FIFOAddData(fifo, 5);
    printf("FIFOSize=%d\n", FIFOSize(fifo));
    printf("0-element=%d\n", fifo->array[fifo->head]);
    int r;
    FIFOLastData(fifo, &r);
    printf("tail-element=%d\n", r);
    printf("FIFOSize=%d\n", FIFOSize(fifo));
    return 0;
}


