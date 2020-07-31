// LRU (最近最少使用) 缓存机制

#include <stdlib.h>
#include <cstring>
#include <cassert>

#define Nothingness -1

struct node {
    int key;
    int value;
    struct node *prev;
    struct node *next;
};//双向链表

struct hash {
    struct node *unused;//数据的未使用时长
    struct hash *next;//拉链法解决哈希冲突
};//哈希表结构

typedef struct {
    int size;//当前缓存大小
    int capacity;//缓存容量
    struct hash *table;//哈希表
    //维护一个双向链表用于记录 数据的未使用时长
    struct node *head;//后继 指向 最近使用的数据
    struct node *tail;//前驱 指向 最久未使用的数据
} LRUCache;

struct hash *HashMap(struct hash *table, int key, int capacity) {//哈希地址
    int addr = key % capacity;//求余数
    return &table[addr];
}

void HeadInsertion(struct node *head, struct node *cur) {
    if (cur->prev == NULL && cur->next == NULL) {// cur 不在链表中
        cur->prev = head;
        cur->next = head->next;
        head->next->prev = cur;
        head->next = cur;
    } else {// cur 在链表中
        struct node *fisrt = head->next;//链表的第一个数据结点
        if (fisrt != cur) {//cur 是否已在第一个
            cur->prev->next = cur->next;//改变前驱结点指向
            cur->next->prev = cur->prev;//改变后继结点指向
            cur->next = fisrt;//插入到第一个结点位置
            cur->prev = head;
            head->next = cur;
            fisrt->prev = cur;
        }
    }
}

LRUCache *lRUCacheCreate(int capacity) {
    assert(capacity > 0);
    LRUCache *obj = (LRUCache *) malloc(sizeof(LRUCache));
    obj->table = (struct hash *) malloc(capacity * sizeof(struct hash));
    memset(obj->table, 0, capacity * sizeof(struct hash));
    obj->head = (struct node *) malloc(sizeof(struct node));
    obj->tail = (struct node *) malloc(sizeof(struct node));
    //创建头、尾结点并初始化
    obj->head->prev = NULL;
    obj->head->next = obj->tail;
    obj->tail->prev = obj->head;
    obj->tail->next = NULL;
    //初始化缓存 大小 和 容量
    obj->size = 0;
    obj->capacity = capacity;
    return obj;
}

int lRUCacheGet(LRUCache *obj, int key) {
    //取得哈希地址
    struct hash *addr = HashMap(obj->table, key, obj->capacity);
    addr = addr->next;//跳过头结点
    if (addr == NULL) {
        return Nothingness;
    }
    while (addr->next != NULL && addr->unused->key != key) {//寻找密钥是否存在
        addr = addr->next;
    }
    if (addr->unused->key == key) {//查找成功
        HeadInsertion(obj->head, addr->unused);//更新至表头
        return addr->unused->value;
    }
    return Nothingness;
}

void lRUCachePut(LRUCache *obj, int key, int value) {
    struct hash *addr = HashMap(obj->table, key, obj->capacity);//取得哈希地址
    if (lRUCacheGet(obj, key) == Nothingness) {//密钥不存在
        if (obj->size >= obj->capacity) {//缓存容量达到上限
            struct node *last = obj->tail->prev;//最后一个数据结点
            struct hash *remove = HashMap(obj->table, last->key, obj->capacity);//舍弃结点的哈希地址
            struct hash *ptr = remove;
            remove = remove->next;//跳过头结点
            while (remove->unused->key != last->key) {//找到最久未使用的结点
                ptr = remove;
                remove = remove->next;
            }
            ptr->next = remove->next;//在 table[last->key % capacity] 链表中删除结点
            remove->next = NULL;
            remove->unused = NULL;//解除映射
            free(remove);//回收资源
            struct hash *new_node = (struct hash *) malloc(sizeof(struct hash));
            new_node->next = addr->next;//连接到 table[key % capacity] 的链表中
            addr->next = new_node;
            new_node->unused = last;//最大化利用双链表中的结点，对其重映射(节约空间)
            last->key = key;//重新赋值
            last->value = value;
            HeadInsertion(obj->head, last);//更新最近使用的数据
        } else {//缓存未达上限
            //创建(密钥\数据)结点,并建立映射
            struct hash *new_node = (struct hash *) malloc(sizeof(struct hash));
            new_node->unused = (struct node *) malloc(sizeof(struct node));
            new_node->next = addr->next;//连接到 table[key % capacity] 的链表中
            addr->next = new_node;
            new_node->unused->prev = NULL;//标记该结点是新创建的,不在双向链表中
            new_node->unused->next = NULL;
            new_node->unused->key = key;//插入密钥
            new_node->unused->value = value;//插入数据
            HeadInsertion(obj->head, new_node->unused);//更新最近使用的数据
            ++(obj->size);//缓存大小+1
        }
    } else {//密钥已存在
        // lRUCacheGet 函数已经更新双链表表头，故此处不用更新
        obj->head->next->value = value;//替换数据值
    }
}

void lRUCacheFree(LRUCache *obj) {
    free(obj->table);
    free(obj->head);
    free(obj->tail);
    free(obj);
}

