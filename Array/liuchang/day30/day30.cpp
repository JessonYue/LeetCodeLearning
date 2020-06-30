//
// Created by 刘畅 on 2020/6/30.
//

#include "day30.h"
#include "iostream"

typedef struct _LinkedNode {
    int data;
    _LinkedNode *next;
} LinkedNode;

LinkedNode *make(int data);

LinkedNode *make(int data) {
    LinkedNode *node = static_cast<LinkedNode *>(malloc(sizeof(LinkedNode)));
    assert(node);
    node->data = data;
    node->next = nullptr;
    return node;
}

LinkedNode *reverseList(LinkedNode *head);

LinkedNode *reverseList(LinkedNode *head) {
    LinkedNode *node = nullptr;
    LinkedNode *before = nullptr;
    LinkedNode *node1 = head;
    for (int i = 0; i < 5; ++i) {
        LinkedNode *node2 = node1;
        node1 = node1->next;
        node2->next = nullptr;
        if (node == nullptr&&before == nullptr){
            node = node2;
        } else {
            before = node;
            node2->next = node;
            node = node2;
        }
    }
    return node;
}


int main() {
    LinkedNode *node1 = make(1);
    LinkedNode *node2 = make(2);
    node1->next = node2;
    LinkedNode *node3 = make(3);
    node2->next = node3;
    LinkedNode *node4 = make(4);
    node3->next = node4;
    LinkedNode *node5 = make(5);
    node4->next = node5;
    LinkedNode *node = reverseList(node1);

    for (int i = 0; i < 5; ++i) {
        printf("%d\n", node->data);
        node = node->next;
    }
    return 0;
}