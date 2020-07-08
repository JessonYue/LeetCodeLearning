//
// Created by 丰雷 on 2020/7/2.
//

#ifndef LEETCODE_LEARNING_FIFOCACHE_H
#define LEETCODE_LEARNING_FIFOCACHE_H

#include <iostream>
#include <string.h>

#define MAX_SIZE 10

typedef int DATA_TYPE;
typedef char *KEY_TYPE;

typedef struct _Node {
    DATA_TYPE value;
    DATA_TYPE key;
    struct _Node *next;
} Node;

typedef struct _FIFOCache {
    Node *node;
    int length;
} FIFOCache;

/**
 * FIFO 队列初始化
 * @param fifoCache 要初始化的队列
 */
FIFOCache *initQueue();

/**
 * 向 FIFO 中添加一条数据
 * @param fifoCache 添加数据的队列
 * @param data 添加的数据
 */
void enterCache(FIFOCache *fifoCache, int key, int val);

/**
 * 删除 FIFO 中的一条数据
 * @param fifoCache 要操作的队列
 * @param data 删除的数据
 * @return
 */
int deleteCache(FIFOCache *fifoCache, int key);

/**
 * 根据 key 获取数据
 * @param fifoCache
 */
Node* getCache(FIFOCache *fifoCache, int key);

/**
 * 打印所有数据
 * @param fifoCache
 */
void printCache(FIFOCache *fifoCache);


#endif //LEETCODE_LEARNING_FIFOCACHE_H
