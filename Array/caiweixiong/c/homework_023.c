//
// Created by Vashon on 2020/7/2.
//

#include <stdio.h>
#include "list_node.h"

int kthToLast(struct ListNode *head, int k);
void listInsert(struct ListNode **list, int e);
void displayList(struct ListNode *list);
void destroyList(struct ListNode **list);

// 返回倒数第 k 个节点，LeetCode面试题02.02
void homework_023_0202(void) {
    struct ListNode *list;
    listInsert(&list, 0);
    listInsert(&list, 9);
    listInsert(&list, 1);
    listInsert(&list, 2);
    listInsert(&list, 4);
    displayList(list);
    printf("The target is : %d", kthToLast(list, 3));
    destroyList(&list);
}

int kthToLast(struct ListNode *head, int k) {
    if (!head || k < 0)
        return -1;
    int target = -1, index = 1;
    struct ListNode *slow = head, *quick = head;
    while (quick->next && (index != k)) {   // 先让一个指针向前 k 步
        quick = quick->next;
        index++;
    }
    // 当链表有足够的长度才需要进行下面的操作
    if (index == k) {
        while (quick->next) {   // 两个指针同时后移，由于指针的间距就是 k，只有到了链尾，就能得到倒数的 k 节点
            quick = quick->next;
            slow = slow->next;
        }
        target = slow->val;
    }
    return target;
}