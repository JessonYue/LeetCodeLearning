//
// Created by 谢涛 on 2020/7/4.
//
#define MAX_SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int DATA_TYPE;
typedef struct _Node {
    DATA_TYPE value;
    DATA_TYPE key;
    struct _Node *next;
} Node;

typedef struct FIFO {
    Node *node;
    int length;
} FIFO;

FIFO *initQueue(){//初始化链表
    FIFO *fifo = (FIFO *)malloc(sizeof(FIFO));
    Node *node = (Node *)malloc(sizeof(Node));
    if (fifo == NULL || node){
        return NULL;
    }
    memset(fifo,0,sizeof(FIFO));
    memset(node,0,sizeof(Node));
    node->key = -1;
    node->value = 0;
    node->next = NULL;
    fifo->length = 0;
    fifo->node = node;
    return fifo;
}

void addNode(FIFO *fifo, int key, int val){

}