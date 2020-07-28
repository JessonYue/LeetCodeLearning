#include <stdlib.h>
#include <stdio.h>
#include <unordered_map>

using namespace std;

struct LinkedNode {
    int key;
    int value;
    LinkedNode *pre;
    LinkedNode *next;

    LinkedNode() : key(key), value(value), pre(pre), next(next) {}

    LinkedNode(int key, int value) : key(key), value(value), pre(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, LinkedNode *> cache;
    LinkedNode *head;
    LinkedNode *tail;
    int capacity;
    int size;
public:
    LRUCache(int capacity) : capacity(capacity), size(0) {
        head = new LinkedNode();
        tail = new LinkedNode();
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        // 如果 key 存在，先通过哈希表定位，再移到头部
        LinkedNode *node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            //不存在 创建一个节点
            LinkedNode *node = new LinkedNode(key, value);
            //添加进map
            cache[key] = node;
            //添加到头节点
            addToHead(node);
            size++;
            if (size > capacity) {
                // 如果超出容量，删除双向链表的尾部节点
                LinkedNode *remove = removeTail();
                cache.erase(remove->key);
                delete remove;
                size--;
            }
        } else {
            //存在
            LinkedNode *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void moveToHead(LinkedNode *node) {
        removeNode(node);
        addToHead(node);
    }

    void removeNode(LinkedNode *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void addToHead(LinkedNode *node) {
        node->pre = head;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
    }

    LinkedNode *removeTail() {
        LinkedNode *node = tail->pre;
        removeNode(node);
        return node;
    }

    void printfCache() {
        unordered_map<int, LinkedNode *>::iterator iter;
        for (iter = cache.begin(); iter != cache.end(); iter++)
            printf("key is %d,value is %d\n", iter->first, iter->second->value);
    }
};


int main() {
    LRUCache *cache = new LRUCache(2 /* 缓存容量 */ );

    printf("----------1-----------\n");

    cache->put(1, 1);
    cache->printfCache();

    printf("----------2-----------\n");

    cache->put(2, 2);
    cache->printfCache();

    printf("----------3-----------\n");

    cache->get(1);       // 返回  1
    cache->printfCache();

    printf("----------4-----------\n");

    cache->put(3, 3);    // 该操作会使得关键字 2 作废
    cache->printfCache();

    printf("----------5-----------\n");

    cache->get(2);       // 返回 -1 (未找到)
    cache->printfCache();

    printf("----------6-----------\n");


    cache->put(4, 4);    // 该操作会使得关键字 1 作废
    cache->printfCache();

    printf("----------7-----------\n");

    printf("result is %d\n", cache->get(1));       // 返回 -1 (未找到)
    cache->printfCache();

    printf("----------8-----------\n");

    cache->get(3);       // 返回  3
    cache->printfCache();

    printf("----------9-----------\n");

    cache->get(4);       // 返回  4
    cache->printfCache();

    return 0;
}