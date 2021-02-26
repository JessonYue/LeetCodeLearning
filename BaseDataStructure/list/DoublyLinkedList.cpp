//
// Created by Jesson on 2021/2/4.
//

#include "DoublyLinkedList.h"

/*尾插法 */
pNode *InitList(pNode **head, int n)
{
     pNode *p, *s;
     (*head) = (pNode *)malloc(sizeof(pNode));
     if ((*head) == NULL)
         exit(0);
     (*head)->next = NULL;//head的prev和next均指向NULL
     (*head)->prev = NULL;
     p = (*head);//p指向head
     int i;
     for (i = 0; i < n; ++i)
     {
         s = (pNode *)malloc(sizeof(pNode));
         if (s == NULL)
             exit(0);
         printf("Input the value of the %dth node:", i + 1);
         scanf("%d", &s->data);
         s->next = NULL;
         p->next = s;
         s->prev = p;
         p = s;//p指向尾节点
     }
     return p;
}

/* 遍历打印 */
void PrintList(pNode *head)
{
    pNode *p;
    p = head->next;
    if (head->next == NULL)
        printf("the list is empty\n");
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
/* 清空链表 */
void DeleteList(pNode **head)
{
    pNode *p;
    while((*head)->next != NULL)
    {
        p = (*head);
        p->next->prev = NULL;
        (*head) = p->next;
        free(p);
    }
}
/* 查找链表内的某个值 */
int SearchList(pNode *head)
{
    int number;
    printf("Values are about to be deleted:");
    scanf("%d", &number);
    pNode *p;
    p = head->next;
    while(p != NULL)
    {
        if (p->data == number)
        {
            return number;
        }
        p = p->next;
    }
    return 0;
}
/* 删除链表中某个元素，令p的前驱节点和后驱节点相互指向即可，如果p是尾节点则直接将前驱节点指向NULL*/
void DelNumqList(pNode **head, int n)
{
    int i;
    pNode *p;
    p = (*head)->next;
    for (i = 1; i < n; ++i)
        p = p->next;
    if(p->next == NULL)
    {
        p->prev->next = NULL;
        free(p);
    }
    else
    {
        p->next->prev = p->prev;
        p->prev->next = p->next;
        free(p);
    }
}

int main(int argc, char const *argv[])
{
    int n, element, flag;
    pNode *head, *last;
    /***************************************************************/
    printf("Please input the size of the list:");
    scanf("%d", &n);
    last = InitList(&head, n);//初始化链表并赋值,返回尾节点last
    printf("%d %d \n", head->next->data, last->data); //打印为第一个元素和最后一个元素
    PrintList(head);
    /***************************************************************/
    flag = SearchList(head); //搜索某个值并删除节点
    if (flag > 0 && flag <= n)
    {
        DelNumqList(&head, flag);
        PrintList(head);
    }
    else
        printf("Element does not exist, cannot be deleted\n");
    /***************************************************************/
    DeleteList(&head);//清空列表
    PrintList(head);
    return 0;
}