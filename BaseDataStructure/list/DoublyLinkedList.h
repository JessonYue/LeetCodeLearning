//
// Created by Jesson on 2021/2/4.
//

#ifndef BASEDATASTRUCTURE_DOUBLYLINKEDLIST_H
#define BASEDATASTRUCTURE_DOUBLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node pNode;
struct Node
{
     int data;
     pNode *prev, *next; //双指针
};


pNode *InitList(pNode **head, int n);
void PrintList(pNode *head);
void DeleteList(pNode **head);
int  SearchList(pNode *head);
void DelNumqList(pNode **head, int n);

#endif //BASEDATASTRUCTURE_DOUBLYLINKEDLIST_H
