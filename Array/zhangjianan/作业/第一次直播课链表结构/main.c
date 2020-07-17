#include <stdio.h>
#include <malloc.h>
#include <semaphore.h>
#include <Signal.h>
#include <stdlib.h> // exit(), EXIT_SUCCESS
#include <pthread.h> // pthread_create(), pthread_join()
#include <assert.h>

typedef int data;
typedef struct Node_ {
    data element_data;
    struct Node_ *next;
} MyNode;

typedef struct LinkedList_ {
    int length;
    MyNode *head;
    MyNode *tail;
} MyLinkedList;

struct Node_ *make(int data);

void free_(struct Node_ *node);

void visit_(struct Node_ *node);

MyLinkedList *create();

void destroy(MyLinkedList *myLinkedList);

void append(MyLinkedList *myLinkedList, int data);

void delete(MyLinkedList *myLinkedList, int index);

void visit_list(MyLinkedList *myLinkedList);


struct Node_ *make(int data) {
    MyNode *node = malloc(sizeof(MyNode *));
    node->element_data = data;
    node->next = NULL;
    return node;
}

void free_(MyNode *node) {
    free(node);
    node = NULL;
}

void visit_(MyNode *node) {
    printf("[%p | %d]\n", node, node->element_data);
}

MyLinkedList *create() {
    MyLinkedList *list = malloc(sizeof(MyLinkedList *));
    assert(list != NULL);
    list->length = 0;
    list->head = make(0);
    list->tail = make(0);
    list->head->next = list->tail;
    return list;
}

void destroy(MyLinkedList *myLinkedList) {
    MyNode *current = myLinkedList->head->next;
    while (current != myLinkedList->tail) {
        MyNode *next = current->next;
        free_(current);
        current = next;
    }
    free_(myLinkedList->head);
    free_(myLinkedList->tail);
    free(myLinkedList);
    myLinkedList = NULL;
}

void append(MyLinkedList *myLinkedList, int data) {
    myLinkedList->tail->element_data = data;
    MyNode *node = make(0);
    myLinkedList->tail->next = node;
    myLinkedList->tail = node;
    myLinkedList->length++;
}

void delete(MyLinkedList *list, int index) {
    MyNode *crr = list->head->next;
    MyNode *pre = list->head;
    int i = 0;
    while (crr != list->tail) {
        if (i == index) {
            break;
        }
        i++;
        pre = crr;
        crr = crr->next;
    }
    pre->next = crr->next;
    free_(crr);
    list->length--;
}

void visit_list(MyLinkedList *myLinkedList) {
    printf("=========list========\n");
    printf("length  %d\n",myLinkedList->length );
    MyNode *node = myLinkedList->head->next;
    while (node != NULL) {
        printf("[%p | %d]\n", node, node->element_data);
        node = node->next;
    }
}

void reverse(MyLinkedList *list) {
    MyNode *pre = NULL;
    MyNode *cre = list->head;
    MyNode *next = cre->next;
    while (cre != NULL) {
        cre->next = pre;
        pre = cre;
        cre = next;
        next = (next == NULL ? NULL : cre->next);
    }
    MyNode *node = list->head;
    list->head = list->tail;
    list->tail = node;
}

int main() {
    MyLinkedList *myLinkedList = create();
    append(myLinkedList, 1);
    append(myLinkedList, 2);
    append(myLinkedList, 3);
    append(myLinkedList, 4);
//    delete(myLinkedList,1);
    visit_list(myLinkedList);
    reverse(myLinkedList);
    visit_list(myLinkedList);
    return 0;
}

