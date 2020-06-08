//
// Created by 张俊伟 on 2020/6/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linkedlist.h"

/***************************结点相关************************/
//创建结点
Node *make_node(data value) {
    return make_node_next(value, NULL);
}

Node *make_node_next(data value, Node *next) {
    Node *node = (Node *) malloc(sizeof(Node));
    assert(node != NULL);
    node->next = next;
    node->value = value;
    return node;
}

//销毁结点
void destory_node(Node *node) {
    assert(node != NULL);
//    node->next = NULL;
    free(node);
    node = NULL;
}

/***************************链表相关************************/
//创建链表
Linked_list *create_linkedlist() {
    Linked_list *linkedlist = (Linked_list *) malloc(sizeof(Linked_list));
    assert(linkedlist != NULL);
//    Node *head = make_node(0);
//    Node *tail = make_node(0);
    linkedlist->head = make_node(0);
    linkedlist->tail = make_node(0);
    linkedlist->head->next = linkedlist->tail;
    linkedlist->size = 0;
    return linkedlist;
}

//销毁链表
void destory_linkedlist(Linked_list *linkedList) {
    assert(linkedList != NULL);
    Node *current = linkedList->head->next;
    //释放 head 到 tail 之间的 Node
    while (current != linkedList->tail) {
       Node *next = current->next;
        destory_node(current);
        current = next;
    }
    destory_node(linkedList->head);
    destory_node(linkedList->tail);
    free(linkedList);
    linkedList = NULL;
}

//向链表添加结点
void append(Linked_list *list, data value) {
    insert_node_attail(list, value);
//    list->tail->value = value;
//    Node *node = make_node(0);
//    list->tail->next = node;
//    list->tail = node;
//    list->size += 1;
}

//在指定的 index 处插入结点
void inser_node_atindex(Linked_list *linkedList, data value, int index) {
    assert(index >= 0 && index <= linkedList->size);
    //插入尾部
    if (index == linkedList->size) {
        insert_node_attail(linkedList, value);
        return;
    }

    Node *current = linkedList->head->next;
    Node *prev = linkedList->head;
    int i = 0;
    while (current != linkedList->tail) {
        if (i == index) {
            //找到插入点
            Node *node = make_node_next(value, current);
            prev->next = node;
            break;
        }
        i++;
        prev = current;
        current = current->next;
    }

    linkedList->size += 1;
}

//在链表头部添加结点
void insert_node_athead(Linked_list *linkedList, data value) {
    Node *head = linkedList->head;
    Node *node = make_node_next(value, head->next != NULL ? head->next : linkedList->tail);
    head->next = node;
    linkedList->size++;
}

//在链表尾部添加结点
void insert_node_attail(Linked_list *linkedList, data value) {
    Node *tail = linkedList->tail;
    tail->value = value;
    Node *newtail = make_node(0);
    tail->next = newtail;
    linkedList->tail = newtail;

    linkedList->size++;
}

//在指定的 index 处删除结点
void delete_node_atindex(Linked_list *linkedList, int index) {
    assert(linkedList != NULL);
    assert(index >= 0 && index < linkedList->size);
    Node *current = linkedList->head->next;
    Node *prev = linkedList->head;
    int i = 0;
    while (current != linkedList->tail) {
        if (i == index) {
            prev->next = current->next;
            destory_node(current);
            break;
        }
        prev = current;
        current = current->next;
        i++;
    }
    linkedList->size--;
}

//删除链表第一个结点
void delete_first_node(Linked_list *linkedList) {
    Node *head = linkedList->head;
    if (head->next != NULL) {
        Node *current = head->next;
        head->next = current->next;
        destory_node(current);
        linkedList->size--;
    }
}

//删除链表尾部结点
void delete_last_node(Linked_list *linkedList) {
    Node *current = linkedList->head;
    Node *prev = NULL;
    while (current != linkedList->tail) {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    prev->value = 0;
    linkedList->tail = prev;
    //此时 current 指向原来的 tail
    destory_node(current);
    linkedList->size--;

}

//链表反转
void reverse(Linked_list *linkedList) {
    //原来是 head->A->B->C->D->tail->NULL
    //变为   NULL<-head<-A<-B<-C<-D<-tail
    Node *pre = NULL;
    Node *current = linkedList->head;
    Node *next = current->next;
    while (current != NULL) {
        current->next = pre;
        pre = current;
        current = next;
        next = (next == NULL ? NULL : next->next);
    }
    Node *node = linkedList->head;
    linkedList->head = linkedList->tail;
    linkedList->tail = node;
}

//工具类
void print(Linked_list *linkedList) {
    printf("==========list ===========\n");
    printf("length %d\n", linkedList->size);
    printf("linkedList %p\n", linkedList);
    Node *current = linkedList->head;
    while (current != NULL) {
        printf("Node %p", current);
        current = current->next;
    }
}

void list_foreach(Linked_list *linkedList, list_callback callback) {
    Node *current = linkedList->head->next;
    while (current != linkedList->tail) {
        if (callback != NULL)
            callback(current);
        current = current->next;
    }
}

//Node节点的打印
void visit(Node *node) {
    assert(node != NULL);
    printf("[%p | %d]\n", node, node->value);
}

void list_traverse(Linked_list *linkedList) {
    printf("========遍历开始=========\n");
    list_foreach(linkedList, visit);
}

//test
void list_test() {
    Linked_list *list = create_linkedlist();
    append(list, 100);
    append(list, 101);
    append(list, 102);
    append(list, 103);
    inser_node_atindex(list,4,4);
    inser_node_atindex(list,0,0);
    list_traverse(list);
//    delete_first_node(list);
    delete_node_atindex(list,2);
//    reverse(list);
//    inser_node_atindex(list,-1,-1);
    list_traverse(list);

    destory_linkedlist(list);
    printf("list %p", list);
}

int main() {
    list_test();

    return 0;
}