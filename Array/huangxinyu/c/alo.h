//
// Created by hasee on 2020/6/2.
//

#ifndef LEETCODE_ALO_H
#define LEETCODE_ALO_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

int climbStairs(int n);

int strStr(const char *haystack, const char *needle);

void merge(int *A, int ASize, int m, int *B, int BSize, int n);

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

ListNode *reverseList(ListNode *head, int i);

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);

ListNode *removeNthFromEnd(ListNode *head, int n);

ListNode* oddEvenList(ListNode* head);

bool isPalindrome(ListNode *head);

#endif; //LEETCODE_ALO_H
