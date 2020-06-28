//
// Created by 刘畅 on 2020/6/24.
//

#include "day24.h"
#include "iostream"

typedef  struct Node_ {
    int data;
    Node_ *next;
} Node;



Node *createNode(int data){
    Node_ *node = static_cast<Node_ *>(malloc(sizeof(Node)));
    assert(node != NULL);
    node->next = nullptr;
    node->data = data;
    return node;
}

bool hasCycle(Node *head) {
    Node *slowNode = head;
    Node *fastNode = head;
    for (;;) {
        slowNode = slowNode->next;
        fastNode = fastNode->next->next;
        if (slowNode == fastNode){
            return true;
        }else if (fastNode ==NULL) {
            return false;
        }
    }

}


int main(){
    Node *node1 = createNode(3);
    Node *node2 = createNode(2);
    node1->next = node2;
    Node *node3 = createNode(0);
    node2->next =node3;
    Node *node4 = createNode(4);
    node3->next = node4;
//    node4->next = node2;
    printf("%d\n",hasCycle(node1));

}
