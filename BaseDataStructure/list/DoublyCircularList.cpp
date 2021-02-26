//
// Created by Jesson on 2021/2/4.
//

#include <cstdlib>
#include <cstdio>
#include "DoublyCircularList.h"

void InitList(LinkList *L){
    *L=(LinkList)malloc(sizeof(Node));
    (*L)->next=(*L)->pre=*L;
}

/*利用尾插法插入时，新插入的结点的后驱指向头结点，同时更新头结点的前驱指针指向新加入的结点，
 * 前一个结点的后驱指针更新为指向新的结点。*/
void CreateLink(LinkList L,int n)
{
    LinkList p=L,q;
    while(n--)
    {
        q=(LinkList)malloc(sizeof(Node));
        scanf("%d",&q->data);
        p->next=q;//前一个结点的后驱指针更新为指向新的结点
        q->pre=p;//前一个结点的后驱指针更新为指向新的结点
        q->next=L;//尾插法  新插入的结点的后驱指向头结点
        L->pre=q;//头结点的前驱指针指向新加入的结点，
        p=q;
    }
}

/*双向循环链表的后序遍历操作*/
void TraverseList(LinkList L)
{
    LinkList p=L->pre;
    while(p!=L)
    {
        printf("%d ",p->data);
        p=p->pre;
    }
}

int main()
{
    int n;
    LinkList L;
    InitList(&L);
    scanf("%d",&n);
    CreateLink(L,n);
    TraverseList(L);
    return 0;
}