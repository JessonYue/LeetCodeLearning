//
// Created by Vashon on 2020/6/28.
//

#include <stdio.h>
#include <stdlib.h>
#include "list_node.h"

// 删除链表中的节点，LeetCode第237题
void homework_020_237(void) {
    struct ListNode *list1 = NULL;
    void listInsert(struct ListNode **list, int e);
    void displayList(struct ListNode *list);
    void deleteNode(struct ListNode *node);
    void destroyList(struct ListNode **list);
    listInsert(&list1, 0);
    listInsert(&list1, 9);
    listInsert(&list1, 1);
    listInsert(&list1, 2);
    listInsert(&list1, 4);
    displayList(list1);
    deleteNode(list1->next->next);
    displayList(list1);
    destroyList(&list1);
}

void deleteNode(struct ListNode *node) {
    if (!node || !node->next)
        return;
    struct ListNode *temp = node->next; // 先得到当前节点的下一个节点
    node->next = temp->next;            // 当前节点指向下下个节点
    node->val = temp->val;              // 将下一个节点的值保存下来
    free(temp);                         // 删除下一个节点，因为信息都保持了，就类似删除当前节点了
    temp = NULL;
}