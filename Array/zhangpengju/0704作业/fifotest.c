
// FIFO算法
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
    //数组实现
    int array[ARRAY_SIZE];
    int head;
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
