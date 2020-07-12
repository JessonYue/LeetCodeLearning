#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * 203. 移除链表元素
 * 删除链表中等于给定值 val 的所有节点。
 */
struct ListNode *removeElements(struct ListNode *head, int val) {
    if (head == NULL) {
        return head;
    }

    struct ListNode *tmpHead = malloc(sizeof(struct ListNode));
    tmpHead->val = 0;
    tmpHead->next = NULL;
    struct ListNode *tail = tmpHead;

    while (head != NULL) {
        if (head->val != val) {
            tail->next = head;
            tail = head;
        }
        head = head->next;
    }
    tail->next = NULL;
    struct ListNode * newHead = tmpHead->next;
    free(tmpHead);
    return newHead;
}