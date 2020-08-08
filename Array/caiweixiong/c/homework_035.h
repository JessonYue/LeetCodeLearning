//
// Created by Vashon on 2020/7/29.
//

/**
    运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

    获取数据 get(key) - 如果关键字 (key) 存在于缓存中，则获取关键字的值（总是正数），否则返回 -1。
    写入数据 put(key, value) - 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字/值」。
    当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

    进阶:

    你是否可以在 O(1) 时间复杂度内完成这两种操作？

    示例:

    LRUCache cache = new LRUCache( 2 // 缓存容量 );

    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // 返回  1
    cache.put(3, 3);    // 该操作会使得关键字 2 作废
    cache.get(2);       // 返回 -1 (未找到)
    cache.put(4, 4);    // 该操作会使得关键字 1 作废
    cache.get(1);       // 返回 -1 (未找到)
    cache.get(3);       // 返回  3
    cache.get(4);       // 返回  4
 */

/**
 * 普通思路(链表版)：实测，由于太耗时，leetcode boom 了。。。
 * 1.创建一个存放相关数据的容器，其中包含数据域的起始地址，当前存在元素，最大支持元素个数等字段
 * 2.每次存放数据，若存在，则覆盖，并将数据放在数据段尾，
 *      若不存在：
 *          一、容量未满：开辟空间，并修改相应的值后将数据放在数据段尾
 *          二、容量已满：将数据段头内容覆盖，放在数据段尾
 * 3.每次取数据，在链表中找，存在则返回对应的值，不存在则返回 -1
 *
 * 进阶思路一：
 * 1.创建一个计算下标值的 hash 函数，可以为 key % capacity = hash，产生冲突时，使用地址展开法解决
 * 2.对应的，创建一个双向链表：
 *      get值时，先通过第一个步的 hash 查询是否存在 key
 *          不存在，直接返回 -1
 *          已存在，将用双指针法查询链表，找到对应节点，将节点置于链尾并返回值
 *      put值时，先通过第一个步的 hash 查询是否存在 key
 *          不存在
 *              容量已满：将链头节点 key 值取出，将新 key 覆盖 hash 表中链头 key 的位置，并将链头节点置于链尾
 *              容量未满：通过第一步得到 index，并存放 key，新建节点链接在链尾
 *          已存在
 *              通过第一步得到 index，并存放新 value，对应节点链接在链尾
 *
 * 进阶思路二：这个版本是空间换时间，会浪费大量的内存
 * 1.进阶思路一完成后，通过了 LeetCode 的校验，但是效率太低了，而且 hash 冲突严重，hash 表形同虚设
 * 2.现在设计第二种方式，先不考虑用树形结构，设计为：
 *      缓存大小
 *      已用大小
 *      hash 表：大小为缓存大小 + 1，每个位置都是一个记录了前后节点与下一节点的双向链表 + 单向链表，双向链表用于记录 Lru，单向用于处理 hash 冲突
 *      头结点与尾节点
 * 3.put 数据：
 *      容量已满：
 *          已存在：
 *              
 *          未存在：
 *      容量未满：
 */

#ifndef C_HOMEWORK_035_H
#define C_HOMEWORK_035_H

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);

 * lRUCachePut(obj, key, value);

 * lRUCacheFree(obj);
*/

// 方法一：单向链表法
typedef struct kvnode_1 {
    int key;
    int value;
    struct kvnode_1 *next;
} KVNode_1;

typedef struct {
    int length;
    int capacity;
    KVNode_1 *head;
} LRUCache_1;

LRUCache_1 *lRUCacheCreate_1(int capacity);

int lRUCacheGet_1(LRUCache_1 *obj, int key);

void lRUCachePut_1(LRUCache_1 *obj, int key, int value);

void lRUCacheFree_1(LRUCache_1 *obj);


// 方法二：散列表 + 双向链表法
typedef struct kvnode_2 {
    int key;
    int value;
    struct kvnode_2 *prior; // 前驱节点
    struct kvnode_2 *next;  // 后继节点
} KVNode_2;

typedef struct {
    int length;
    int capacity;
    int *hashTable;
    KVNode_2 *head; // 链头
    KVNode_2 *tail; // 链尾
} LRUCache_2;

int hash_2(LRUCache_2 *obj, int key);

LRUCache_2 *lRUCacheCreate_2(int capacity);

bool keyIsExist_2(int *hashTable, int length, int key);

KVNode_2 *findNode_2(LRUCache_2 *obj, int key);

void changeLinkPosition_2(LRUCache_2 *obj, KVNode_2 *node);

int lRUCacheGet_2(LRUCache_2 *obj, int key);

void lRUCachePut_2(LRUCache_2 *obj, int key, int value);

void lRUCacheFree_2(LRUCache_2 *obj);


// 方法三：参考了 HashMap 源码，与 LinkHashMap 源码，散列表 + LinkHashMap + 双向链表，内存肯定大很多，但是速度应该提升不少
typedef struct kvnode_3 {   // 节点
    int key, value;
    struct kvnode_3 *before, *after, *next;
} KVNode_3;

typedef struct {            // 缓存结构
    int size, outCap, inCap;    // 当前使用大小、外部传进来的限制大小，内部实际的限制大小
    KVNode_3 **hashTable, *head, *tail;
} LRUCache_3;

int tableSizeFor(unsigned int capacity);

KVNode_3 *newNode(LRUCache_3 *obj, int key, int value);

void afterNodeAccess(LRUCache_3 *obj, KVNode_3 *node);

// 寻找一个合适的节点，并修改它的 key
KVNode_3 *findSuitableNode(LRUCache_3 *obj, int newKey);

// 找到最少使用的节点，将改节点从双链表中移除
KVNode_3 *changeHashTable(LRUCache_3 *obj, int newKey);

LRUCache_3 *lRUCacheCreate_3(int capacity);

int lRUCacheGet_3(LRUCache_3 *obj, int key);

void lRUCachePut_3(LRUCache_3 *obj, int key, int value);

void lRUCacheFree_3(LRUCache_3 *obj);

#endif //C_HOMEWORK_035_H
