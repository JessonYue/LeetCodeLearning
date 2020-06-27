//
// Created by 刘畅 on 2020/6/26.
//

#include "day26.h"
#include <iostream>

typedef struct _ListNode {
    int data;
    _ListNode *next;
} ListNode;

ListNode *deleteNode(ListNode *node,int data);

ListNode *make(int data);

ListNode *deleteNode(ListNode *node,int data){
    ListNode *deleteNode = node;
    ListNode *beforeNode = nullptr;
    for (int i = 0; i < 4 ; ++i) {
        if (deleteNode->data ==data){
            beforeNode->next = deleteNode->next;
            break;
        } else {
            beforeNode = deleteNode;
            deleteNode = deleteNode->next;
        }
    }
    return beforeNode;
}

ListNode *make(int data) {
    ListNode *node = static_cast<ListNode *>(malloc(sizeof(ListNode)));
    memset(node, 0, sizeof(ListNode));
    node->data = data;
    node->next = nullptr;
    return node;
}

int main() {
    ListNode *node1 = make(4);
    ListNode *node2 = make(5);
    node1->next = node2;
    ListNode *node3 = make(1);
    node2->next = node3;
    ListNode *node4 = make(9);
    node3->next = node4;
//    ListNode * testNode = node1;
//    for (int i = 0; i <4 ; ++i) {
//        printf("%d\n",testNode->data);
//        testNode = testNode->next;
//    }
    ListNode *bNode = deleteNode(node1,5);
    for (int i = 0; i <4 ; ++i) {
        printf("%d\n",bNode->data);
        bNode = bNode->next;
    }
    return 0;
}