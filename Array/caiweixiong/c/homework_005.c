//
// Created by Vashon on 2020/6/5.
//

#include "list_node.h"
#include <stdio.h>

// 相交链表，LeetCode第160题
void homework_005_160(void) {
    // 初始化两个相交的链表
    // !!!!!!!!!!!!!!!!再一次掉坑!!!，list1、list2忘记赋初始值，然后程序崩了。。。谨记！赋初始值
    struct ListNode *list1 = NULL, *list2 = NULL, *temp = NULL, *node = NULL;
    void listInsert(struct ListNode **list, int e);
    listInsert(&list1, 0);
    listInsert(&list1, 9);
    listInsert(&list1, 1);
    listInsert(&list1, 2);
    listInsert(&list1, 4);
    listInsert(&list2, 3);
    temp = list1;
    // 将指针指向值域为：2 的节点
    while (temp != NULL && temp->val != 2)
        temp = temp->next;
    // 将temp节点接在list2后面，形成相交节点
    if (temp != NULL)
        list2->next = temp;
    // 获取相交节点
    struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB);
    node = getIntersectionNode(list1, list2);
    if (node == NULL)
        printf("链表 list1 与 list2 无相交点");
    else
        printf("相交节点的值域为：%d", node->val);
    // 释放资源
    // !!!切断list2的next域，不然释放资源进入死循环
    list2->next = NULL;
    void destroyList(struct ListNode **list);
    destroyList(&list1);
    destroyList(&list2);
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *listA = headA, *listB = headB, *lastNode = NULL;
    if (headA == NULL || headB == NULL)
        return NULL;
    if (listA == listB)
        return listA;
    while (listA != listB) {
        // 过滤链表A
        if (listA->next != NULL)
            listA = listA->next;
        else {
            if (lastNode != NULL) {
                // 链表A到达链尾了，而且链尾不空，也就是链表B比较短，先到达了链表尾，并将链尾存了起来，如果它们地址值不一样，则肯定不相交
                if (lastNode != listA)
                    return NULL;
                else
                    // 证明有相交节点，将listA指向链表B
                    listA = headB;
            } else {
                // 链表A已经到达链尾，将链尾节点存起来
                lastNode = listA;
                // 将listA指向链表B
                listA = headB;
            }
        }
        // 过滤链表B
        if (listB->next != NULL)
            listB = listB->next;
        else {
            if (lastNode != NULL) {
                // 链表B到达链尾了，而且链尾不空，也就是链表A比较短，先到达了链表尾，并将链尾存了起来，如果它们地址值不一样，则肯定不相交
                if (lastNode != listB)
                    return NULL;
                else
                    // 证明有相交节点，将listB指向链表A
                    listB = headA;
            } else {
                // 链表B已经到达链尾，将链尾节点存起来
                lastNode = listB;
                // 将listB指向链表A
                listB = headA;
            }
        }
        // 经过了上面的过滤，指向最后判断它们的地址值一样，返回它们的其中一个即可
        if (listA == listB)
            return listA;
    }
    return NULL;
}

// 方法二，基本思路不变，但是代码更整洁
struct ListNode *getIntersectionNode_(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL)
        return NULL;
    struct ListNode *listA = headA, *listB = headB;
    int lenA = 1, lenB = 1;
    while (listA->next && lenA++ && (listA = listA->next)); // 寻找尾节点
    while (listB->next && lenB++ && (listB = listB->next)); // 寻找尾节点
    if (listA == listB) {   // 链尾相等，必定有交点
        listA = headA, listB = headB;
        int diff = lenA - lenB; // 得到两条链的长度差
        if (lenA > lenB)
            while (diff-- && (listA = listA->next));    // 过滤A链
        else
            while (diff++ && (listB = listB->next));    // 过滤B链
        while (listA && listB) {    // 寻找两条链的第一个交点
            if (listA == listB)
                return listA;
            listA = listA->next;
            listB = listB->next;
        }
    }
    return NULL;
}