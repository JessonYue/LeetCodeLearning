
#include <malloc.h>
#include <assert.h>

//
// Created by 张佳男 on 2020/6/30.
//
typedef int data;
struct Node_ {
    data element_data;
    struct Node_ *next;
} Node;
struct LinkedList {
    int length;
    struct Node_ *head;
    struct Node_ *tail;
};

struct Node_ *make(int data);

struct Void *print(struct Node_ *node);

void free_(struct Node_ *node);

struct LinkedList *creatLinkedList();

void detroyLinkedList(struct LinkedList *nodeList);

void deleteLinkedListByIndex(struct LinkedList *nodeList,int index);

void printLinkedList(struct LinkedList *nodeList);

void reverseLinkedList(struct LinkedList *nodeList);

struct LinkedList *insertLinkedList(struct LinkedList *nodeList,int data);

void printLinkedList(struct LinkedList *nodeList){
    assert(nodeList != NULL);
   struct Node_* current= nodeList->head->next;
    printf("=====head=%d\n", nodeList->head->element_data);
    while (current != nodeList->tail) {
        printf("%d\n", current->element_data);
        current = current->next;
    }
    printf("=====tail=%d\n", nodeList->tail->element_data);
}

void deleteLinkedListByIndex(struct LinkedList *nodeList,int index){
    assert(index>0&&index<nodeList->length);
    struct Node_* current=nodeList->head->next;
    struct Node_* pre=nodeList->head;
    unsigned int i=0;
    while (current != nodeList->tail) {
        if (i==index) {
            break;
        }
        pre=current;
        current = current->next;
        i++;
    }
    pre->next = current->next;
    nodeList->length -= 1;
    free(current);
}


struct LinkedList *insertLinkedList(struct LinkedList *nodeList,int data){
    assert(nodeList != NULL);
    nodeList->tail->element_data=data;
    struct Node_* newNode=make(0);
    nodeList->tail->next=newNode;
    nodeList->tail=newNode;
    nodeList->length += 1;
}
struct LinkedList *creatLinkedList() {
    struct LinkedList *list = malloc(sizeof(struct LinkedList));
    assert(list != NULL);
    list->length = 0;
    list->head = make(0);
    list->tail = make(0);
    list->head->next = list->tail;//通过next绑定了指向关系
    return list;
}
/**
 * linkedlist的销毁
 */
void detroyLinkedList(struct LinkedList *nodeList) {
    struct Node_* current=nodeList->head->next;
    while (current != nodeList->tail) {
        struct Node_* next=current->next;
        free_(current);
        current=next;
    }
    free_(nodeList->head);
    free_(nodeList->tail);
    free_(nodeList);
    nodeList = NULL;
}

void free_(struct Node_ *node) {
    if (node != NULL) {
        free(node);
        node = NULL;
    }
};

struct Void *print(struct Node_ *node) {
    while (node != NULL) {
        printf("%d\n", node->element_data);
        node = node->next;
    }
}

struct Node_ *make(int data) {
    struct Node_ *node = malloc(sizeof(Node));
    assert(node != NULL);
    node->element_data = data;
    node->next = NULL;
    return node;
}

/**
 * 节点翻转
 * @param head
 * @return
 */
void reverseLinkedList(struct LinkedList *nodeList) {
    struct Node_ *newNode = NULL;
    struct Node_ *cur = nodeList->head;
    //12345
    while (cur != NULL
            ) { //当前节点是3 新节点21
        struct Node_ *catchnode = cur->next;//缓存下一个节点 缓存4
        cur->next = newNode;//当前节点3指向新节点21
        newNode = cur;//把当前节点321重新赋值给新节点
        cur = catchnode;//当前节点指向下个节点4
    }
    struct Node_*node=nodeList->head;
    nodeList->tail = node;
    nodeList->head=newNode;
}