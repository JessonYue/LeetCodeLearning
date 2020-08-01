//
// Created by 吴超 on 2020/7/31.
//
#include <stdlib.h>

/**
 * 双向链表
 */

typedef struct Node {
    struct Node *prev;
    struct Node *next;
    int value;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
} LinkedList;

LinkedList *createLinkedList() {
    LinkedList *linkedList = malloc(sizeof(LinkedList));
    linkedList->head = malloc(sizeof(Node));
    linkedList->tail = malloc(sizeof(Node));
    linkedList->head->next = linkedList->tail;
    linkedList->tail->prev = linkedList->head;
    return linkedList;
}

void recycleNode(Node* node){
    node->prev = NULL;
    node->next = NULL;
    free(node);
}

void recycleLinkedList(LinkedList* linkedList){
    Node* node = linkedList->head->next;
    while(node!=linkedList->tail){
        Node* next = node->next;
        recycleNode(next);
        node = next;
    }
    recycleNode(linkedList->head);
    recycleNode(linkedList->tail);
}

Node *newNode(int value) {
    Node *node = malloc(sizeof(Node));
    node->value = value;
    return node;
}

void linkNodeToHead(LinkedList *linkedList,Node*node){
    linkedList->head->next->prev = node;
    node->next = linkedList->head->next;
    node->prev = linkedList->head;
    linkedList->head->next = node;
}

void linkNodeToTail(LinkedList*linkedList,Node*node){
    linkedList->tail->prev->next = node;
    node->prev = linkedList->tail->prev;
    node->next = linkedList->tail;
    linkedList->tail->prev = node;
}

void addNodeToHead(LinkedList *linkedList, int value) {
    Node *node = newNode(value);
    linkNodeToHead(linkedList,node);
}

void addNodeToTail(LinkedList *linkedList, int value) {
    Node *node = newNode(value);
    linkNodeToTail(linkedList,node);
}

int removeFromHead(LinkedList*linkedList){
    int result = -1;
    if(linkedList->head->next!=linkedList->tail){
        Node* top = linkedList->head->next;
        linkedList->head->next = top->next;
        top->next->prev = linkedList->head;
        result = top->value;
        recycleNode(top);
    }
    return result;
}

int removeFromTail(LinkedList* linkedList){
    int result = -1;
    if(linkedList->tail->prev!=linkedList->head){
        Node* bottom = linkedList->tail->prev;
        linkedList->tail->prev = bottom->prev;
        bottom->prev->next = linkedList->tail;
        result = bottom->value;
        recycleNode(bottom);
    }
    return result;
}

int removeNode(LinkedList * linkedList,int value){
    int result = -1;
    Node* node = linkedList->head->next;
    while(node!=linkedList->tail){
        if(node->value == value){
            node->prev->next = node->next;
            node->next->prev = node->prev;
            result = node->value;
            recycleNode(node);
            break;
        }
        node = node->next;
    }
    return result;
}

int peekTop(LinkedList* linkedList){
    if(linkedList->head->next!=linkedList->tail){
        return linkedList->head->next->value;
    }
    return -1;
}

int peekBottom(LinkedList* linkedList){
    if(linkedList->tail->prev!=linkedList->head){
        return linkedList->tail->prev->value;
    }
    return -1;
}

void moveToHead(LinkedList * linkedList,int value){
    Node* node = linkedList->head->next;
    while(node!=linkedList->tail){
        if(node->value == value){
            node->prev->next = node->next;
            node->next->prev = node->prev;
            linkNodeToHead(linkedList,node);
            break;
        }
    }
}

void moveToTail(LinkedList * linkedList,int value){
    Node* node = linkedList->head->next;
    while(node!=linkedList->tail){
        if(node->value == value){
            node->prev->next = node->next;
            node->next->prev = node->prev;
            linkNodeToTail(linkedList,node);
            break;
        }
    }
}

int findTop(LinkedList* linkedList,int value){
    Node* node = linkedList->head->next;
    while (node!=linkedList->tail){
        if(node->value == value){
            return value;
        }
        node = node->next;
    }
    return -1;
}

int findBottom(LinkedList* linkedList,int value){
    Node* node = linkedList->tail->prev;
    while (node!=linkedList->head){
        if(node->value==value){
            return value;
        }
        node = node->prev;
    }
    return -1;
}



