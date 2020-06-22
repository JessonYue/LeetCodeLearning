//
// Created by 刘畅 on 2020/6/21.
//

#include "day19.h"
#include <iostream>
#include <string.h>

#define MAXSIZE 20

typedef struct MyQueue {
    char data[MAXSIZE];
    int front;
    int rear;
} CharQueue;

CharQueue *createQueue();

bool isFull(CharQueue *queue);

void pushQueue(CharQueue *queue, char data);

void removeDuplicates(CharQueue *charQueue);

CharQueue *createQueue() {
    CharQueue *charQueue = (CharQueue *) malloc(sizeof(CharQueue));
    charQueue->front = charQueue->rear = 0;
    return charQueue;
}

bool isFull(CharQueue *queue) {
    return queue->rear == MAXSIZE;
}

void pushQueue(CharQueue *queue, char const *data) {
    if (isFull(queue)) {
        return;
    }
    for (int i = 0; i < strlen(data); ++i) {
        queue->data[queue->rear] = data[i];
        queue->rear++;
    }

}

void removeDuplicates(CharQueue *charQueue) {
    int num = -1;
    for (int k = 0; k < charQueue->rear; ++k) {
        if (charQueue->data[k] == charQueue->data[k + 1]) {
            num = k;
            break;
        }
    }
    if (num != -1) {
        char temp;
        int i, j;
        for (i = num; i < num + 2; ++i) {
            temp = charQueue->data[num];
            for (j = num; j < charQueue->rear; ++j) {
                charQueue->data[j] = charQueue->data[j + 1];
            }
            charQueue->data[j] = temp;
        }
        charQueue->rear = charQueue->rear - 2;
        removeDuplicates(charQueue);
    }
//    return;
}


int main() {
    CharQueue *charQueue = createQueue();
    pushQueue(charQueue, "abbaca");
//    for (int i = 0; i < charQueue->rear; ++i) {
//        printf("%c\n", charQueue->data[i]);
//    }
    removeDuplicates(charQueue);
    removeDuplicates(charQueue);
    for (int i = 0; i < charQueue->rear; ++i) {
        printf("%c\n", charQueue->data[i]);
    }
//    char a[7] = {'a', 'b', 'b', 'a', 'c', 'a'};
//    int len = sizeof(a) / sizeof(a[0]);
//
//
//    for (int i = 0; i < len; ++i) {
//        printf("%c ", a[i]);
//    }
    return 0;
}
