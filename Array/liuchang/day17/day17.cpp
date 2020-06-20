//
// Created by 刘畅 on 2020/6/19.
//

#include "day17.h"

#define MAXSIZE 20

#include <iostream>

typedef struct MyStack {
    int top;
    int front ;
    int data[MAXSIZE];
} StackQE;

typedef struct QueueMy {
    StackQE *frontStack;
    StackQE *rearStack;
} QueueQE;

QueueQE *createQueueQE();

void pushQueueQE(QueueQE *queueQe, int data);

void popQueueQE(QueueQE *queueQe);

void freeQueueQE(QueueQE *queueQe);

QueueQE *createQueueQE() {
    QueueQE *queueQe = (QueueQE *) malloc(sizeof(QueueQE));
    queueQe->frontStack = (StackQE *) malloc(sizeof(StackQE));;
    queueQe->frontStack->top = -1;
    queueQe->frontStack->front = 0;
    queueQe->rearStack = (StackQE *) malloc(sizeof(StackQE));
    queueQe->rearStack->top = -1;
    queueQe->rearStack->front =0;
    return queueQe;

}

void pushQueueQE(QueueQE *queueQe, int data) {
    if (queueQe->rearStack->top == MAXSIZE - 1) {
        return;
    }
    if (queueQe->frontStack->top != -1) {
        for (int i = queueQe->frontStack->top; i > -1; i--) {
            queueQe->rearStack->top++;
            queueQe->rearStack->data[queueQe->rearStack->top] = queueQe->frontStack->data[i];
            queueQe->frontStack->top--;
        }
    }

    queueQe->rearStack->top++;
    queueQe->rearStack->data[queueQe->rearStack->top] = data;

}

void popQueueQE(QueueQE *queueQe) {

    if (queueQe->frontStack->top == MAXSIZE - 1) {
        return;
    }
    if (queueQe->rearStack->top != -1) {
        for (int i = queueQe->rearStack->top; i > -1; i--) {
            queueQe->frontStack->top++;
            queueQe->frontStack->data[queueQe->frontStack->top] = queueQe->rearStack->data[i];
            queueQe->rearStack->top--;
        }
    }

    queueQe->frontStack->data[queueQe->frontStack->top] = queueQe->frontStack->data[queueQe->frontStack->top - 1];
    queueQe->frontStack->top--;

}

void freeQueueQE(QueueQE *queueQe) {
    free(queueQe->rearStack);
    free(queueQe->frontStack);
    free(queueQe);
}

int main() {
    QueueQE *queueQe = createQueueQE();
    pushQueueQE(queueQe, 1);
    pushQueueQE(queueQe, 2);
    pushQueueQE(queueQe, 3);
    pushQueueQE(queueQe, 4);
    pushQueueQE(queueQe, 5);
    pushQueueQE(queueQe, 6);
    pushQueueQE(queueQe, 7);
    for (int i = 0; i <= queueQe->rearStack->top; i++) {
        printf("%d\n", queueQe->rearStack->data[i]);
    }
    printf("========\n");
    popQueueQE(queueQe);
    for (int j = 0; j <= queueQe->frontStack->top; j++) {
        printf("%d\n", queueQe->frontStack->data[j]);

    }
    printf("========\n");
    pushQueueQE(queueQe, 8);
    for (int k = 0; k < queueQe->rearStack->top+1 ; k++) {
        printf("%d\n",queueQe->rearStack->data[k]);
    }
    printf("=========\n");
    popQueueQE(queueQe);
    for (int j = 0; j <= queueQe->frontStack->top; j++) {
        printf("%d\n", queueQe->frontStack->data[j]);

    }
    return 0;
}
