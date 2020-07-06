//
// Created by 丰雷 on 2020/7/2.
//
#include <mm_malloc.h>
#include "FIFOCache.h"


FIFOCache *initQueue() {
    FIFOCache *fifoCache = static_cast<FIFOCache *>(malloc(sizeof(FIFOCache)));
    Node *node = static_cast<Node *>(malloc(sizeof(Node)));
    if (fifoCache == nullptr || node == nullptr) {
        printf("FIFOCache memory allocation failed\n");
        return NULL;
    }
    memset(fifoCache, 0, sizeof(FIFOCache));
    memset(node, 0, sizeof(Node));
    node->key = -1;
    node->value = 0;
    node->next = nullptr;
    fifoCache->length = 0;
    fifoCache->node = node;
    return fifoCache;
}


int deleteCache(FIFOCache *fifoCache, int key) {
    if (fifoCache == nullptr) {
        printf("FIFOCache is null\n");
        return 0;
    }
    Node *slow = fifoCache->node->next;
    Node *fast = fifoCache->node->next;
    while (fast != nullptr) {
        if (fast->key == key) {
            slow->next = fast->next;
            fifoCache->length--;
            return 1;
        }
        slow = fast;
        fast = fast->next;
    }
    return 0;
}

void enterCache(FIFOCache *fifoCache, int key, int val) {
    if (fifoCache == nullptr) {
        printf("FIFOCache is null\n");
        return;
    }

    Node *node = static_cast<Node *>(malloc(sizeof(Node)));
    if (node == nullptr) {
        printf("Node memory allocation failed\n");
        return;
    }
    memset(node, 0, sizeof(Node));
    node->key = key;
    node->value = val;
    node->next = nullptr;
    if (fifoCache->length == MAX_SIZE) {
        fifoCache->node = fifoCache->node->next;
        fifoCache->length--;
    }

    Node *head = fifoCache->node;
    while (head->next != nullptr) {
        head = head->next;
    }
    head->next = node;
    fifoCache->length++;
}

Node *getCache(FIFOCache *fifoCache, int key) {
    if (fifoCache == nullptr) {
        printf("FIFOCache is null\n");
        return NULL;
    }
    Node *head = fifoCache->node;
    while (head != nullptr) {
        if (head->key == key) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}


void printCache(FIFOCache *fifoCache) {
    Node *node = fifoCache->node->next;
    for (int i = 0; i < fifoCache->length; ++i) {
        printf("Node[%d,%d]  ", node->key, node->value);
        node = node->next;
    }
    printf("\n");
}