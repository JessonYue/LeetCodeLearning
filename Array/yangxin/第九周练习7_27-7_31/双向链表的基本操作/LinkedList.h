//
// Created by 12 on 2020/8/1.
//

#ifndef LEETCODESTUDY_LINKEDLIST_H
#define LEETCODESTUDY_LINKEDLIST_H

#include <malloc.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node *pre;
    struct Node *next;

} Node;
//双向链表
struct LinkedList {
    struct Node *head;
    struct Node *tail;
    int size;
} LinkedList;

struct LinkedList *initLinkedList() {
    struct LinkedList *linkedList = malloc(sizeof(LinkedList));
    linkedList->head = calloc(sizeof(Node), 1);
    linkedList->tail = calloc(sizeof(Node), 1);
    linkedList->head->next = linkedList->tail;
    linkedList->tail->pre = linkedList->head;
    return linkedList;
}

void addTail(struct LinkedList *linkedList, int val) {
    struct Node *pre = linkedList->tail->pre;
    struct Node *node = malloc(sizeof(Node));
    node->data = val;
    node->pre = pre;
    node->next = linkedList->tail;
    pre->next = node;
    linkedList->tail->pre = node;
}

void addHead(struct LinkedList *linkedList, int val) {
    struct Node *first = linkedList->head->next;
    struct Node *node = malloc(sizeof(Node));
    node->data = val;
    node->pre = linkedList->head;
    node->next = first;
    first->pre = node;
    linkedList->head->next = node;
}

struct Node *removeLast(struct LinkedList *linkedList) {
    if (linkedList->head->next == linkedList->tail) {
        return NULL;
    }

    struct Node *pre = linkedList->tail->pre;
    struct Node *ppre = pre->pre;
    ppre->next = linkedList->tail;
    linkedList->tail->pre = ppre;
    pre->next = NULL;
    pre->pre = NULL;
    return pre;
}

struct Node *removeFirst(struct LinkedList *linkedList) {
    if (linkedList->head->next == linkedList->tail) {
        return NULL;
    }
    struct Node *first = linkedList->head->next;
    struct Node *second = first->next;
    linkedList->head->next = second;
    second->pre = linkedList->head;
    first->next = NULL;
    first->pre = NULL;
    return first;
}

struct Node *getFirst(struct LinkedList *linkedList) {
    if (linkedList->head->next == linkedList->tail) {
        return NULL;
    }
    struct Node *first = linkedList->head->next;
    return first;
}

struct Node *getLast(struct LinkedList *linkedList) {
    if (linkedList->head->next == linkedList->tail) {
        return NULL;
    }
    struct Node *last = linkedList->tail->pre;
    return last;
}

void freeLinkedList(struct LinkedList *linkedList) {
    while (linkedList->head->next != linkedList->tail) {
        struct Node *node = removeLast(linkedList);
        free(node);
    }
    free(linkedList);
}

void printlnLinkedList(struct LinkedList *linkedList) {
    struct Node *node = linkedList->head->next;
    while (node != linkedList->tail) {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {

    struct LinkedList* linkedList = initLinkedList();
    addHead(linkedList, 1);
    addTail(linkedList,2);
    addHead(linkedList,3);
    addHead(linkedList,4);
    addTail(linkedList,6);
    printlnLinkedList(linkedList);
    printf("get last === %d\n",getLast(linkedList)->data);
    printf("remove last === %d\n",removeLast(linkedList)->data);

    printlnLinkedList(linkedList);
    printf("get first === %d\n",getFirst(linkedList)->data);
    printf("remove first === %d\n",removeFirst(linkedList)->data);
    printlnLinkedList(linkedList);
    freeLinkedList(linkedList);
    return 0;
}

#endif //LEETCODESTUDY_LINKEDLIST_H
