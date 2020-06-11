//
// Created by Vashon on 2020/6/11.
//

#include "list_node.h"
#include <stdio.h>


// 奇偶链表，LeetCode第328题
void homework_009_328(void) {
    struct ListNode *list = NULL;
    void displayList(struct ListNode *list);
    void destroyList(struct ListNode **list);
    void listInsert(struct ListNode **list, int e);
    struct ListNode *oddEvenList(struct ListNode *);
    listInsert(&list, 1);
    listInsert(&list, 2);
    listInsert(&list, 3);
    listInsert(&list, 4);
    printf("排列前链表节点元素为： ");
    displayList(list);
    list = oddEvenList(list);
    printf("排列后链表节点元素为： ");
    displayList(list);
    destroyList(&list);
}

struct ListNode *oddEvenList(struct ListNode *head) {
    // 空链表，一个元素的链表，两个元素的链表都是不需要重排的
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return head;
    struct ListNode *list1 = head, *prior1 = list1, *next1, *list2 = head->next, *prior2 = list2, *next2;
    int len = 1;
    while (prior1->next != NULL && prior2->next != NULL) {  // 1,2,3,4,null
        if (len++ % 2) {    // 1->3，保持原链不变的前提下，对二取模不为0的就是奇数节点
            next1 = prior1->next->next;
            prior1->next = next1;
            prior1 = next1;
        } else {            // 2->4
            next2 = prior2->next->next;
            prior2->next = next2;
            prior2 = next2;
        }
    }
    prior1->next = list2;   // 将奇数链与偶数链连在一起
    prior2->next = NULL;
    return list1;
}