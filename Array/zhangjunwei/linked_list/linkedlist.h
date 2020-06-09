//
// Created by 张俊伟 on 2020/6/7.
//

#ifndef LICODE_LINKEDLIST_H
#define LICODE_LINKEDLIST_H
#define data int
//节点
typedef struct Node_ {
    data value;
    struct Node_ *next;
} Node;

//链表
typedef struct Linked_list_ {
    int size;
    Node *head;//头结点
    Node *tail;//尾结点
} Linked_list;

/***************************结点相关************************/
//创建结点
Node *make_node(data value);

Node *make_node_next(data value, Node *next);

//销毁结点
void destory_node(Node *node);

/***************************链表相关************************/
//创建链表
Linked_list *create_linkedlist();

//销毁链表
void destory_linkedlist(Linked_list *linkedList);

//向链表添加结点
void append(Linked_list *list, data value);

//在指定的 index 处插入结点
void inser_node_atindex(Linked_list *linkedList, data value, int index);

//在链表头部添加结点
void insert_node_athead(Linked_list *linkedList, data value);

//在链表尾部添加结点
void insert_node_attail(Linked_list *linkedList, data value);

//在指定的 index(范围[0~size-1]) 处删除结点
void delete_node_atindex(Linked_list *linkedList, int index);

//删除链表第一个结点
void delete_first_node(Linked_list *linkedList);

//删除链表尾部结点
void delete_last_node(Linked_list *linkedList);

void reverse(Linked_list* linkedList);

//工具类
void print(Linked_list * list);

typedef void (*list_callback)(Node *node);
void list_foreach(Linked_list *list, list_callback callback);
void list_traverse(Linked_list *linkedList);
//test
void list_test();
#endif //LICODE_LINKEDLIST_H
