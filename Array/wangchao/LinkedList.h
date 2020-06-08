//
// Created by  wangchao on 2020/6/8.
//

#ifndef C_DEMO_LINKEDLIST_H
#define C_DEMO_LINKEDLIST_H

#endif //C_DEMO_LINKEDLIST_H

typedef int data;
//node的定义
struct Node_{
    int data;
    Node_* next;
};

//这里定义的是链表
struct LinkedList_{
    int length;
    Node_* head;
    Node_* tail;
};


//设计函数，具体实现在cpp文件里面去做

Node_* make(int data);
//free资源，这里一定要注意不能与api的free重名，编译可以通过，但是运行结果不正确，坑死
void myfree(Node_* node);
//node的访问
void visit(Node_* node);
//创建链表，初始化的时候只有head, tail
LinkedList_* create();
//append,也可以想象是尾部插入
void append(LinkedList_* linkedList, int data);

//工具类
void print(LinkedList_* list);