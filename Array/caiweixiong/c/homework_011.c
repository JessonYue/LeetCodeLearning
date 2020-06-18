//
// Created by Vashon on 2020/6/15.
//

#include "list_node.h"
#include <stdlib.h>
#include <stdio.h>

// 用队列实现栈，LeetCode第225题
void homework_011_225(void) {
    MyStack *myStackCreate();
    void myStackPush(MyStack *, int);
    int myStackPop(MyStack *obj);
    int myStackTop(MyStack *obj);
    int myStackEmpty(MyStack *obj);
    void myStackFree(MyStack *obj);

    MyStack *stack = myStackCreate();
    myStackPush(stack, 3);
    int param_2 = myStackPop(stack);
    int param_3 = myStackTop(stack);
    int param_4 = myStackEmpty(stack);
    printf("param_2:%d, param_3:%d, param_4:%d\n", param_2, param_3, param_4);
    myStackFree(stack);
}

// 初始化栈
MyStack *myStackCreate() {
    MyStack *stack = malloc(sizeof(MyStack));
    stack->front = NULL;
    stack->rear = NULL;
    return stack;
}

// 压栈
void myStackPush(MyStack *obj, int x) {
    // 栈后进先出的特性，所以，头插法建立队列，就能最大程度的优化栈
    if (!obj)
        return;
    // 创建新节点
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->val = x;
    if ((!obj->rear) && (!obj->front))    // 首次创建节点
        obj->rear = obj->front = node;
    else {  // 再次创建，头插法建队
        node->next = obj->front;
        obj->front = node;
    }
}

// 弹栈，并返回弹出元素
int myStackPop(MyStack *obj) {
    int ele = 0;
    if (!obj || ((!obj->rear) && (!obj->front)))    // 栈空时，返回0
        return ele;
    ele = obj->front->val;
    Node *node = obj->front;        // 取出队首节点
    if (obj->front == obj->rear) {  // 只有一个元素
        obj->front = NULL;
        obj->rear = NULL;
    } else {
        obj->front = node->next;
    }
    free(node);
    return ele;
}

// 获取栈顶元素
int myStackTop(MyStack *obj) {
    if (!obj || ((!obj->rear) && (!obj->front)))
        return 0;
    else
        return obj->front->val;
}

// 栈是否为空
int myStackEmpty(MyStack *obj) {
    if (!obj || ((!obj->rear) && (!obj->front)))
        return 1;
    else
        return 0;
}

// 释放栈
void myStackFree(MyStack *obj) {
    if (!obj)
        return;
    Node *node = obj->front;
    while (node) {
        obj->front = node->next;
        free(node);
        node = obj->front;
    }
    free(obj);
}