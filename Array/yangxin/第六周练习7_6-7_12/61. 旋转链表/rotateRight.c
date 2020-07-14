#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * 61. 旋转链表
 * 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 */
struct ListNode *rotateRight(struct ListNode *head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    int size = 1;
    struct ListNode *tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        size++;
    }

    if (size == k || k % size == 0) {
        return head;
    }

    tail->next = head;
    int tailIndex = size - (k % size) - 1;
    tail = head;
    while (tailIndex > 0) {
        tailIndex--;
        tail = tail->next;
    }
    head = tail->next;
    tail->next = NULL;
    return head;
}