//
// Created by Vashon on 2020/7/27.
//

#ifndef HOMEWORK_LISTNODE_H
#define HOMEWORK_LISTNODE_H

#include <iostream>
#include <cassert>

using namespace std;

struct ListNode {
    explicit ListNode(int value) : val(value), next(nullptr) {}

    ListNode(int value, ListNode *&node) : val(value), next(node) {}

    int val;
    ListNode *next;
};

// 创建链表头节点
void createHeadNode(ListNode *&node, int value);

// 插入节点(尾部)
bool insertNode(ListNode *&head, int value);

// 删除节点(对应节点值)
bool deleteNode(ListNode *&head, int value);

// 销毁链表
void destroyList(ListNode *&head);

// 显示链表内容
void displayList(ListNode *&head);


#endif //HOMEWORK_LISTNODE_H
