//
// Created by 12 on 2020/6/8.
//
#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * 链表相交
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    if (headA == headB) {
        return headA;
    }

    int aLength = 0;
    int bLength = 0;
    struct ListNode *a = headA;
    struct ListNode *b = headB;
    while (a != NULL) {
        aLength++;
        a = a->next;
    }

    while (b != NULL) {
        bLength++;
        b = b->next;
    }

    if (a != b) {
        return NULL;
    }
    a = headA;
    b = headB;
    int k = aLength - bLength;
    while (k != 0) {
        if (k > 0) {
            k--;
            a = a->next;
        } else {
            k++;
            b = b->next;
        }
    }

    while (a != b) {
        a = a->next;
        b = b->next;
    }

    return a;
}

/**
 * 面试题24. 反转链表
 * 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
 */
struct ListNode *reverseList(struct ListNode *head) {
    if (head == NULL) {
        return head;
    }

    struct ListNode *pre = NULL;
    struct ListNode *current = head;
    struct ListNode *next = current->next;

    while (next != NULL) {
        current->next = pre;
        pre = current;
        current = next;
        next = current->next;
    }

    current->next = pre;

    return current;
}

/**
 * 21. 合并两个有序链表
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 */

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    if (l1 == NULL) {
        return l2;
    }

    if (l2 == NULL) {
        return l1;
    }

    struct ListNode *head = malloc(sizeof(struct ListNode));
    //c语言里要赋值null，不然好像就指向不知道的地方去了。c语言里一切值都要初始化
    head->next = NULL;
    struct ListNode *a = NULL;
    struct ListNode *b = NULL;
    if (l1->val < l2->val) {
        head->val = l1->val;
        a = l1->next;
        b = l2;
    } else {
        head->val = l2->val;
        a = l1;
        b = l2->next;
    }

    struct ListNode *current = head;
    while (a != NULL && b != NULL) {
        if (a->val < b->val) {
            current->next = a;
            a = a->next;
        } else {
            current->next = b;
            b = b->next;
        }
        current = current->next;
    }

    while (a != NULL) {
        current->next = a;
        a = a->next;
        current = current->next;
    }

    while (b != NULL) {
        current->next = b;
        b = b->next;
        current = current->next;
    }

    return head;
}

void main() {
    struct ListNode * l1 = malloc(sizeof(struct ListNode));
    l1->val = 1;
    struct ListNode * l2 = malloc(sizeof(struct ListNode));
    l1->next = l2;
    l2->val =2;
    struct ListNode * l3 = malloc(sizeof(struct ListNode));
    l2->next = l3;
    l3->val =4;
    l3->next = NULL;

    struct ListNode * l11 = malloc(sizeof(struct ListNode));
    l11->val = 1;
    struct ListNode * l12 = malloc(sizeof(struct ListNode));
    l11->next = l12;
    l12->val =3;
    struct ListNode * l13 = malloc(sizeof(struct ListNode));
    l12->next = l13;
    l13->val =4;
    l13->next = NULL;

    struct ListNode * head = mergeTwoLists(l1, l11);

    while (head != NULL) {
        printf("%d->", head->val);
        head = head->next;
    }
}