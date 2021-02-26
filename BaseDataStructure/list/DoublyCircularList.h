//
// Created by Jesson on 2021/2/4.
//

#ifndef BASEDATASTRUCTURE_DOUBLYCIRCULARLIST_H
#define BASEDATASTRUCTURE_DOUBLYCIRCULARLIST_H


typedef struct tagNode
{
    int data;
    struct tagNode *pre,*next;
}Node,*LinkList;


void InitList(LinkList *L);//初始化双向循环链表
void CreateLink(LinkList L,int n);//尾插法创建循环链表
void TraverseList(LinkList L);//双向循环链表的后序遍历操作
#endif //BASEDATASTRUCTURE_DOUBLYCIRCULARLIST_H
