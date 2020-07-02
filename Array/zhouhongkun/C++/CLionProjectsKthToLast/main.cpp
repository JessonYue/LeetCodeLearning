#include <iostream>
#include <cstring>
#include "MyNode.h"

/**
 * 初始化头节点
 * @return
 */
Node *init_node_head(){
    Node *headN = static_cast<Node*>(malloc(sizeof(Node)));
    if(headN == nullptr){
        return NULL;
    }
    memset(headN, 0, sizeof(headN));
    headN->data = 0;
    headN->next = NULL;
}

/**
 * 生成一个节点
 * @param data
 * @return
 */
Node *node_init(int data){
    Node *headN = static_cast<Node*>(malloc(sizeof(Node)));
    if(headN == nullptr){
        return NULL;
    }
    memset(headN, 0, sizeof(headN));
    headN->data = data;
    headN->next = NULL;
    return headN;
}

/**
 * 在尾部添加节点
 * @param node
 * @param newNode
 */
void add_node_end(Node *node, Node *newNode){
    Node *cur_head_node = node;
    while(cur_head_node->next != nullptr){
        cur_head_node = cur_head_node->next;
    }
    newNode->next = cur_head_node->next;
    cur_head_node->next = newNode;
}

/**
 * 打印链表
 * @param node
 */
void printf_node(Node *node){
    Node *tmp = node->next;
    while(tmp != nullptr){
        printf("%d->", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

/**
 * 删除倒数第K个节点
 * @param node
 * @param totalSize 
 * @param k
 * @return
 */
Node * delReciprocalNode(Node *node, int totalSize, int k){
    Node *tmp = node->next;
    Node *head = node;
    int index = 0;
    while (tmp != nullptr){
        if(index == totalSize - k){
            head->next = tmp->next;
            break;
        } else {
            index++;
            tmp = tmp->next;
            head = head->next;
        }
    }
    return head;
}

int main() {
    int key[] = {3, 25, 6, 31, 17, 9, 56};
    Node *headNode = init_node_head();
    for(int i=0; i<7; i++){
        Node *newNode = node_init(key[i]);
        add_node_end(headNode, newNode);
    }

    printf_node(headNode);
    delReciprocalNode(headNode, 7, 4);
    printf_node(headNode);
    return 0;
}

