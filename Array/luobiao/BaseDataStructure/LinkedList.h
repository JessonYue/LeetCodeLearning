//
// Created by Jesson on 2020/6/10.
//

#ifndef BASEDATASTRUCTURE_LINKEDLIST_H
#define BASEDATASTRUCTURE_LINKEDLIST_H


typedef int data;
//这里定义的链表的节点Node
typedef struct Node_{
    int data;
    Node_* next;
}Node;
//这里定义的是链表
typedef struct LinkedList_{
    int length;
    Node_* head;
    Node_* tail;
}LinkedList;


//增加
typedef void (* list_callback)(Node_ *node);

//设计函数
Node_* make(int data);
void myfree(Node_* node);
void visit(Node_* node);
LinkedList_* create();
void destroy(LinkedList_* list);
void append(LinkedList_* list,int data);
void deletelistbyindex(LinkedList_* list,int index);
void reverse(LinkedList_* list);

//工具类
void print(LinkedList_* list);
void list_foreach(LinkedList_ *list, list_callback callback);

//test
void list_test();



#endif //BASEDATASTRUCTURE_LINKEDLIST_H
