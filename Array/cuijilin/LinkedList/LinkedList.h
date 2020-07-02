//
// Created by 崔继霖 on 2020/6/16.
//

#ifndef ALGO_C_LINKEDLIST_H
#define ALGO_C_LINKEDLIST_H

#define TRUE 1
#define FALSE 0

typedef int data;
typedef struct Node {
    data value;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    int length;
} LinkedList;

Node *createNode(data value);

void *freeNode(Node *node);

LinkedList *createLinkedList();

void destroyLinkedList(LinkedList *linkedList);

void removeNthFromEnd(LinkedList *linkedList,data n);

void *isLinkedListEmpty(LinkedList *linkedList);

void appendLinkedList(LinkedList *linkedList, data value);

void deleteNodeByIndex(LinkedList *linkedList, int index);

// 翻转
void reverseLinkedList(LinkedList *linkedList);

// 相交链表(某一节点后链表完全一样)
Node *getIntersectionNode(Node *headA, Node *headB);

//合并2个有序链表
Node *mergeTwoLists(Node *n1, Node *n2);

// 奇偶元素聚合
Node *oddEvenList(LinkedList *linkedList);

Node *getMidNode(LinkedList *linkedList);


// 回文列表: 使用快慢指针，慢指针在进行操作的时候，顺带的进行链表的翻转，在进行半个链表之间的比较
int isPalindrome(LinkedList *linkedList);

void printLinkedList(Node *head);

void test_list();

#endif //ALGO_C_LINKEDLIST_H
