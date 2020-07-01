//
// Created by 刘畅 on 2020/7/1.
//

#include "day31.h"
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


int kthToLast(LinkedNode *head, int k,int size);

int kthToLast(LinkedNode *head, int k,int size) {
    int count = 0;
    while (head->next!= nullptr){
        if (count == size-k){
            return head->data;
        } else {
            head = head->next;
        }
        count++;
    }

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
    printf("%d\n",kthToLast(node1,2,5));
    return 0;
}