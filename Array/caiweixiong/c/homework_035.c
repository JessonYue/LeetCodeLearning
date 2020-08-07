//
// Created by Vashon on 2020/7/28.
//

#include "homework_035.h"

// 方法一
LRUCache_1 *lRUCacheCreate_1(int capacity) {
    LRUCache_1 *lruCache = malloc(sizeof(LRUCache_1));
    assert(lruCache != NULL);
    lruCache->length = 0;
    lruCache->capacity = capacity;
    lruCache->head = NULL;
    return lruCache;
}

int lRUCacheGet_1(LRUCache_1 *obj, int key) {
    if (!obj || obj->length == 0)
        return -1;
    KVNode_1 *head = obj->head, *curr = head, *next = head->next;
    int value = -1;
    if (curr->key == key) {
        if (next) { // 有多个节点
            while (next->next)  // 找到链尾节点
                next = next->next;
            // 将最近使用的插到链尾
            obj->head = obj->head->next;
            curr->next = NULL;
            next->next = curr;
        }
        value = curr->value;
    } else {
        if (next) {
            if (next->key == key) { // 第二个元素就是目标节点
                curr->next = next->next;
                next->next = NULL;
                while (curr->next)
                    curr = curr->next;
                curr->next = next;
                value = next->value;
            } else {
                while (next->next) {
                    curr = next;
                    next = next->next;
                    if (next->key == key) { // 找到目标节点，跟上面一样的操作
                        curr->next = next->next;
                        next->next = NULL;
                        while (curr->next)
                            curr = curr->next;
                        curr->next = next;
                        value = next->value;
                        break;
                    }
                }
            }
        }
    }

    return value;
}

void lRUCachePut_1(LRUCache_1 *obj, int key, int value) {
    if (!obj)
        return;
    KVNode_1 *head = obj->head, *curr = head, *next = NULL;
    if (obj->length == obj->capacity) { // 当容量已满，也就是不需要开辟空间，直接覆盖
        next = head->next;
        if (curr->key == key) {
            while (next->next)  // 找到链尾节点
                next = next->next;
            // 将最近使用的插到链尾
            obj->head = obj->head->next;
            curr->next = NULL;
            curr->value = value;
            next->next = curr;
        } else {
            if (next) {
                if (next->key == key) { // 第二个元素就是目标节点
                    curr->next = next->next;
                    next->next = NULL;
                    next->value = value;
                    while (curr->next)
                        curr = curr->next;
                    curr->next = next;
                } else {
                    bool isExist = false;   // 标记该 Key 是否存在于链表
                    while (next->next) {
                        curr = next;
                        next = next->next;
                        if (next->key == key) { // 找到目标节点，跟上面一样的操作
                            isExist = true;
                            curr->next = next->next;
                            next->next = NULL;
                            next->value = value;
                            while (curr->next)
                                curr = curr->next;
                            curr->next = next;
                            break;
                        }
                    }
                    if (!isExist) { // 链表中不存在，将链头节点覆盖并置于链尾
                        curr = head;
                        next = head->next;
                        while (next->next)  // 找到链尾节点
                            next = next->next;
                        // 将最近使用的插到链尾
                        obj->head = obj->head->next;
                        curr->next = NULL;
                        curr->key = key;
                        curr->value = value;
                        next->next = curr;
                    }
                }
            } else {
                curr->key = key;
                curr->value = value;
            }
        }
    } else {
        if (obj->length == 0) { // 第一次添加节点
            KVNode_1 *node = malloc(sizeof(KVNode_1));
            assert(node != NULL);
            node->value = value;
            node->key = key;
            node->next = NULL;
            obj->head = node;
            obj->length++;
        } else {
            next = head->next;
            if (curr->key == key) {
                if (next) {
                    while (next->next)   // 找到链尾节点
                        next = next->next;
                    // 将最近使用的插到链尾
                    obj->head = obj->head->next;
                    curr->next = NULL;
                    curr->value = value;
                    next->next = curr;
                } else {
                    curr->value = value;
                }
            } else {
                if (next) {
                    if (next->key == key) { // 第二个元素就是目标节点
                        curr->next = next->next;
                        next->next = NULL;
                        while (curr->next)
                            curr = curr->next;
                        curr->next = next;
                        next->value = value;
                    } else {
                        bool isExist = false;   // 标记该 Key 是否存在于链表
                        while (next->next) {
                            curr = next;
                            next = next->next;
                            if (next->key == key) { // 找到目标节点，跟上面一样的操作
                                isExist = true;
                                curr->next = next->next;
                                next->next = NULL;
                                while (curr->next)
                                    curr = curr->next;
                                curr->next = next;
                                next->value = value;
                                break;
                            }
                        }
                        if (!isExist) { // 当不存在 key
                            KVNode_1 *node = malloc(sizeof(KVNode_1));
                            assert(node != NULL);
                            node->value = value;
                            node->key = key;
                            node->next = NULL;
                            next->next = node;
                            obj->length++;
                        }
                    }
                } else {
                    KVNode_1 *node = malloc(sizeof(KVNode_1));
                    assert(node != NULL);
                    node->value = value;
                    node->key = key;
                    node->next = NULL;
                    curr->next = node;
                    obj->length++;
                }
            }
        }
    }
}

void lRUCacheFree_1(LRUCache_1 *obj) {
    if (obj != NULL) {
        KVNode_1 *head = obj->head;
        while (head) {
            KVNode_1 *temp = head;
            head = head->next;
            free(temp);
        }
        free(obj);
        obj = NULL;
    }
}

/**
 * 进阶思路：
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
 */
// 方法二
int hash_2(LRUCache_2 *obj, int key) {
    return key % obj->capacity;
}

LRUCache_2 *lRUCacheCreate_2(int capacity) {
    LRUCache_2 *lruCache = malloc(sizeof(LRUCache_2));
    assert(lruCache != NULL);
    int *hashTable = malloc(sizeof(int) * capacity);
    assert(hashTable != NULL);
    for (int i = 0; i < capacity; hashTable[i++] = -1);
    lruCache->hashTable = hashTable;
    lruCache->capacity = capacity;
    lruCache->length = 0;
    lruCache->head = NULL;
    lruCache->tail = NULL;
    return lruCache;
}

bool keyIsExist_2(int *hashTable, int length, int key) {
    int *table = hashTable;
    int head = 0, tail = length - 1;
    while (head <= tail) {
        if (table[head++] == key || table[tail--] == key)
            return true;
    }
    return false;
}

KVNode_2 *findNode_2(LRUCache_2 *obj, int key) {
    KVNode_2 *prior = obj->head, *next = obj->tail;
    while (1) {     // 寻找合适的节点
        if (prior->key == key) return prior;
        else if (next->key == key) return next;
        else {
            prior = prior->next;
            if (prior->key == key) return prior;
            else if (prior == next) return NULL;
            else next = next->prior;
        }
    }
}

void changeLinkPosition_2(LRUCache_2 *obj, KVNode_2 *node) {
    KVNode_2 *head = obj->head, *tail = obj->tail, *target = node;
    if (target->prior || target->next) {  // 链表至少存在 2 个节点
        if (target->prior && target->next) {  // 存在前驱与后继节点
            target->prior->next = target->next;
            target->next->prior = target->prior;
        } else {
            if (target->prior) {    // 这种情况就是已经到达链尾，无需任何操作
                return;
            } else {    // 这种情况是头结点就是目标节点，将头节点放到链尾
                obj->head = obj->head->next;
                obj->head->prior = NULL;
                target = head;
            }
        }
        // 将目标节点放到链尾
        target->next = NULL;
        target->prior = tail;
        tail->next = target;
        obj->tail = target;
    }
}

int lRUCacheGet_2(LRUCache_2 *obj, int key) {
    if (!obj || key <= 0) return -1;
    int index = hash_2(obj, key);
    int *hashTable = obj->hashTable;
    int length = obj->length;
    int keyT = hashTable[index];

    // 当 hash 表中对应位置的 key 与传进来的 key 不同时，才需要进一步判断
    if ((keyT != key) && !keyIsExist_2(hashTable, length, key))
        return -1;

    KVNode_2 *target = findNode_2(obj, key);
    changeLinkPosition_2(obj, target);

    return target->value;
}

void lRUCachePut_2(LRUCache_2 *obj, int key, int value) {
    if (!obj || key <= 0) return;
    int index = hash_2(obj, key);
    int *hashTable = obj->hashTable;
    int length = obj->length;
    int capacity = obj->capacity;
    int keyT = hashTable[index];

    if (length == capacity) { // 容器已满
        if ((keyT == key) || keyIsExist_2(hashTable, length, key)) {
            KVNode_2 *target = findNode_2(obj, key);
            target->value = value;
            changeLinkPosition_2(obj, target);
        } else {    // 不存在该节点
            // 将头结点的数据直接覆盖，然后将头结点放到尾节点处
            KVNode_2 *head = obj->head;
            int newIndex = 0, hKey = head->key;
            for (; newIndex < length; ++newIndex) {
                if (hashTable[newIndex] == hKey) break;
            }
            hashTable[newIndex] = key;
            if (newIndex != index)  // 替换对应位置的 key 可以尽量减少 hash 冲突
                hashTable[index] ^= hashTable[newIndex] ^= hashTable[index] ^= hashTable[newIndex];
            head->key = key;
            head->value = value;
            changeLinkPosition_2(obj, head);
        }
    } else {
        if ((keyT == key) || keyIsExist_2(hashTable, length, key)) {  // 存在节点
            KVNode_2 *target = findNode_2(obj, key);
            target->value = value;
            changeLinkPosition_2(obj, target);
        } else {    // 不存在该节点
            if (keyT == -1) {
                hashTable[index] = key;     // 将节点的key存放到散列表对应的位置
            } else {
                int newIndex = (index + 1) >= capacity ? 0 : (index + 1);
                while (newIndex != index) { // 寻找合适的位置
                    if (hashTable[newIndex] == -1) break;
                    else if (++newIndex == capacity) newIndex = 0;   // 当索引到达尾部，回到开头
                }
                hashTable[newIndex] = key;   // 将节点的key存放到散列表对应的位置
                hashTable[index] ^= hashTable[newIndex] ^= hashTable[index] ^= hashTable[newIndex];
            }
            KVNode_2 *node = malloc(sizeof(KVNode_2)), *tail = obj->tail;
            assert(node != NULL);
            node->key = key;
            node->value = value;
            node->next = NULL;
            if (tail) {
                node->prior = tail;
                tail->next = node;
                obj->tail = node;
            } else {
                node->prior = NULL;
                obj->head = node;
                obj->tail = node;
            }
            obj->length++;
        }
    }
}

void lRUCacheFree_2(LRUCache_2 *obj) {
    if (obj != NULL) {
        KVNode_2 *head = obj->head;
        while (head) {  // 释放每一个节点
            KVNode_2 *temp = head;
            head = head->next;
            free(temp);
        }
        int *hashTable = obj->hashTable;
        if (hashTable)  // 释放散列表
            free(hashTable);
        free(obj);      // 释放缓存容器
        obj = NULL;
    }
}

// 方法三
int tableSizeFor(unsigned int capacity) {   // 将容量变为 2 的幂次方
    unsigned int n = capacity - 1;
    int m;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    m = n;
    return (m < 0) ? 1 : (n >= INT_MAX) ? INT_MAX : (m + 1);
}

KVNode_3 *newNode(LRUCache_3 *obj, int key, int value) {
    KVNode_3 *node = malloc(sizeof(KVNode_3)), *tail;
    assert(node != NULL);
    node->key = key;
    node->value = value;
    node->before = NULL;
    node->after = NULL;
    node->next = NULL;
    // 链接双向链表，将新节点直接链接到链尾
    tail = obj->tail;
    obj->tail = node;
    if (tail) {
        node->before = tail;
        tail->after = node;
    } else {
        obj->head = node;
    }
    obj->size++;
    return node;
}

void afterNodeAccess(LRUCache_3 *obj, KVNode_3 *node) {
    KVNode_3 *tail = obj->tail;
    if (tail != node) {
        KVNode_3 *p = node, *b = p->before, *a = p->after;
        p->after = NULL;    // 当前节点的后继断开
        if (b == NULL)      // 当前节点不存在前驱，既头结点
            obj->head = a;
        else
            b->after = a;   // 当前节点存在前驱，修改其后继的指向
        if (a != NULL)      // 当前节点存在后继节点
            a->before = b;  // 修改后继节点的前驱指向
        else
            tail = b;       // 当前节点的后继节点不存在，既前驱就是最后一个元素
        if (tail == NULL)   // 两种情况：本来就不存在链尾节点、当前节点的前驱为空
            obj->head = p;  // 当前节点就是头结点
        else {              // 将当前节点插到链尾
            p->before = tail;
            tail->after = p;
        }
        obj->tail = p;      // 修改链尾
    }
}

KVNode_3 *findSuitableNode(LRUCache_3 *obj, int newKey) {
    KVNode_3 **table = obj->hashTable, *head = NULL, *prior = NULL, *next = NULL;
    int key = obj->head->key, index = key & (obj->inCap - 1);
    head = prior = table[index];
    next = prior->next;
    if (head->key == key) { // 头节点就是目标节点
        table[index] = next;
        head->next = NULL;
        head->key = newKey;
        return head;
    } else {
        while (next->next) {// 寻找目标节点
            if (next->key == key) {
                prior->next = next->next;
                next->next = NULL;
                next->key = newKey;
                return next;
            }
            prior = next;
            next = next->next;
        }
        prior->next = NULL;
        next->key = newKey;
        return next;
    }
}

KVNode_3 *changeHashTable(LRUCache_3 *obj, int newKey) {    // 将对应的节点从 hash 表上的单链表移除
    // 1.找到最少使用的节点
    // 2.计算该节点在 hash 表中的位置
    // 3.若与目标节点一致，直接覆盖，若不一致移出 hash 表
    KVNode_3 **table = obj->hashTable, *head = NULL, *prior = NULL, *next = NULL;
    int key = obj->head->key, headIndex = key & (obj->inCap - 1), newIndex = newKey & (obj->inCap - 1);
    if (headIndex == newIndex) {
        head = table[headIndex];
        next = head->next;
        if (head->key == key) { // 头节点就是目标节点
            next = head;
        } else {
            while (next->next) {// 寻找目标节点
                if (next->key != key)
                    next = next->next;
            }
        }
        next->key = newKey;
        return next;
    } else {
        return findSuitableNode(obj, newKey);
    }
}

LRUCache_3 *lRUCacheCreate_3(int capacity) {
    LRUCache_3 *lruCache = malloc(sizeof(LRUCache_3));
    assert(lruCache != NULL);
    lruCache->outCap = capacity;
    int inCap = tableSizeFor(capacity);
    lruCache->inCap = inCap;
    KVNode_3 **kvNode = malloc(sizeof(KVNode_3 *) * inCap), **temp = kvNode;
    assert(kvNode != NULL);
    for (int i = 0; i < inCap; (*temp) = NULL, ++temp, ++i);
    lruCache->hashTable = kvNode;
    lruCache->head = NULL;
    lruCache->tail = NULL;
    lruCache->size = 0;
    return lruCache;
}

int lRUCacheGet_3(LRUCache_3 *obj, int key) {
    if (!obj || !obj->head || key <= 0) return -1;
    int index = key & (obj->inCap - 1);
    KVNode_3 **table = obj->hashTable, *node, *temp;
    node = table[index];
    if (node == NULL)
        return -1;
    else {
        if (node->key == key)   // 是目标节点，值覆盖即可
            temp = node;
        else {
            while (1) {
                if ((temp = node->next) == NULL)   // 找不到对应的节点
                    return -1;
                if (temp->key == key) break;       // 存在这个节点，直接跳出循环即可
                node = temp;
            }
        }
        afterNodeAccess(obj, temp); // 修改 lur 链表的位置
        return temp->value;
    }
}

void lRUCachePut_3(LRUCache_3 *obj, int key, int value) {
    if (!obj || key <= 0) return;
    int index = key & (obj->inCap - 1);
    KVNode_3 **table = obj->hashTable, *head, *node, *temp;
    head = node = table[index];
    if (node == NULL) {   // 节点不存在
        if (obj->size == obj->outCap) {  // 容量已满
            temp = findSuitableNode(obj, key);
            temp->value = value;
            table[index] = temp;   // 找到最少使用的节点，将它的值覆盖并存到 hash 表
        } else {    // 创建新节点存到 hash 表
            table[index] = newNode(obj, key, value);
            return;
        }
    } else {
        if (node->key == key) {   // hash 表第一个节点就是目标节点，值覆盖即可
            node->value = value;
            temp = node;
        } else {    // 发生 hash 冲突，从单链表寻找对应节点
            while (1) {
                if ((temp = node->next) == NULL) {  // 找不到对应的节点
                    if (obj->size == obj->outCap) {   // 容量已满，且是新的 key,需要修改 hash 表
                        temp = changeHashTable(obj, key);
                        temp->value = value;
                        if (head != temp)  // 单链表只有一个节点
                            node->next = temp;
                        break;
                    } else {     // 容量未满，直接创建新节点
                        temp = newNode(obj, key, value);
                        node->next = temp;
                        return;
                    }
                }
                if (temp->key == key) { // 存在这个节点，直接跳出循环即可
                    temp->value = value;
                    break;
                }
                node = temp;
            }
        }
    }
    afterNodeAccess(obj, temp); // 修改 lur 链表的位置
}

void lRUCacheFree_3(LRUCache_3 *obj) {
    if (obj) {
        KVNode_3 *head = obj->head, *temp;
        while (head) {   // 移除所有节点
            temp = head->after;
            free(head);
            head = temp;
        }
        free(obj->hashTable);
        free(obj);
    }
}

// LRU缓存机制，LeetCode第146题
void homework_035_146(void) {
    // 方法一
//    int value = 0;
//    LRUCache_1 *cache1 = lRUCacheCreate_1(3);
//    lRUCachePut_1(cache1, 1, 1);
//    lRUCachePut_1(cache1, 2, 2);
//    lRUCachePut_1(cache1, 3, 3);
//    lRUCachePut_1(cache1, 4, 4);
//    value = lRUCacheGet_1(cache1, 4);
//    printf("value is : %d\n", value);
//    value = lRUCacheGet_1(cache1, 3);
//    printf("value is : %d\n", value);
//    value = lRUCacheGet_1(cache1, 2);
//    printf("value is : %d\n", value);
//    value = lRUCacheGet_1(cache1, 1);
//    printf("value is : %d\n", value);
//    lRUCachePut_1(cache1, 5, 5);
//    value = lRUCacheGet_1(cache1, 1);
//    printf("value is : %d\n", value);
//    value = lRUCacheGet_1(cache1, 2);
//    printf("value is : %d\n", value);
//    value = lRUCacheGet_1(cache1, 3);
//    printf("value is : %d\n", value);
//    value = lRUCacheGet_1(cache1, 4);
//    printf("value is : %d\n", value);
//    value = lRUCacheGet_1(cache1, 5);
//    printf("value is : %d\n", value);
//    lRUCacheFree_1(cache1);

    // 方法二
    int value = 0;
    LRUCache_3 *cache1 = lRUCacheCreate_3(2);
    lRUCachePut_3(cache1, 1, 1);
    lRUCachePut_3(cache1, 2, 2);
    value = lRUCacheGet_3(cache1, 1);
    printf("value is : %d\n", value);
    lRUCachePut_3(cache1, 3, 3);
    value = lRUCacheGet_3(cache1, 2);
    printf("value is : %d\n", value);
    lRUCachePut_3(cache1, 4, 4);
    value = lRUCacheGet_3(cache1, 1);
    printf("value is : %d\n", value);
    value = lRUCacheGet_3(cache1, 3);
    printf("value is : %d\n", value);
    value = lRUCacheGet_3(cache1, 4);
    printf("value is : %d\n", value);

//    KVNode_3 *node3_0 = malloc(sizeof(KVNode_3));
//    KVNode_3 *node3_1 = malloc(sizeof(KVNode_3));
//    node3_0->before = NULL;
//    node3_0->after = node3_1;
//    node3_0->key = 99;
//    node3_0->value = 88;
//    node3_0->next = NULL;
//    node3_1->before = node3_0;
//    node3_1->after = NULL;
//    node3_1->key = 100;
//    node3_1->value = 2;
//    node3_1->next = NULL;
//    cache1->hashTable[0] = node3_0;
//    cache1->hashTable[1] = node3_1;
//
//    printf("node_0:key-> % d value-> %d\n", cache1->hashTable[0]->key, cache1->hashTable[0]->value);
//    printf("node_1:key-> % d value-> %d\n", cache1->hashTable[1]->key, cache1->hashTable[1]->value);

//    int value = 0;
//    LRUCache_2 *cache1 = lRUCacheCreate_2(1);
//    lRUCachePut_2(cache1, 2, 1);
//    value = lRUCacheGet_2(cache1, 2);
//    printf("value is : %d\n", value);

    lRUCacheFree_3(cache1);
}
