//
// Created by Vashon on 2020/6/10.
//

#include "list_node.h"
#include <stdio.h>
#include <stdlib.h>

void listInsert(struct ListNode **list, int e);

// 删除链表的倒数第N个节点，LeetCode第19题
void homework_008_019(void) {
    struct ListNode *list = NULL;
    void displayList(struct ListNode *list);
    void destroyList(struct ListNode **list);
//    struct ListNode *removeNthFromEnd(struct ListNode *, int);
    struct ListNode *removeNthFromEnd_(struct ListNode *, int);
    listInsert(&list, 1);
    listInsert(&list, 2);
    listInsert(&list, 3);
    listInsert(&list, 4);
    printf("删除链表节点前的元素为： ");
    displayList(list);
    list = removeNthFromEnd_(list, 2);
    printf("删除链表节点后的元素为： ");
    displayList(list);
    destroyList(&list);
}

// 方法一：常态先获取链表长度，再算出正数第几个节点再进行删除
struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    if (head == NULL || n <= 0)
        return NULL;
    int len = 1, no;
    struct ListNode *temp = head, *target = NULL;
    // 查询链表的长度
    while (temp->next != NULL) {
        temp = temp->next;
        len++;
    }
    if (len < n)
        return head;
    // 获取顺数需要删除的节点索引，从 0 开始
    no = len - n;
    temp = head;
    if (no == 0) {
        target = head;
        head = head->next;
    } else {    // 寻找需要删除节点的前驱节点
        while (--no && (temp = temp->next));
        target = temp->next;
        temp->next = target->next;
    }
    free(target);
    return head;
}

// 方法二：双指针法，当找到了第 n + 1 个节点，再用一个指针从头开始，这样就可以保证两个指针间的元素为 n 个，所以第一轮循环到尾节点时，第二个指针正好在倒数第 n 个节点的前驱节点处
struct ListNode *removeNthFromEnd_(struct ListNode *head, int n) {
    if (head == NULL || n <= 0) {
        return NULL;
    }
    int len = 1;
    struct ListNode *first = head, *second = head, *target = NULL;
    while (first->next != NULL) {   // 寻找需要删除的节点的前驱节点
        first = first->next;
        if (len++ > n)
            second = second->next;
    }
    if (len < n)    // 如果链表的长度比目标数还小，也就是不存在节点，则直接返回原链表
        return head;
    if (len == n) { // 当需要删除的是头节点，则修改头节点后直接删除
        target = head;
        head = head->next;
    } else {        // 删除目标节点
        target = second->next;
        second->next = target->next;
    }
    free(target);   // 删除节点后记得释放资源
    return head;
}