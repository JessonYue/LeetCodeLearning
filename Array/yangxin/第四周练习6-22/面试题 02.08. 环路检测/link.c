#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * 面试题 02.08. 环路检测
 *
 * 给定一个有环链表，实现一个算法返回环路的开头节点。
 * 有环链表的定义：在链表中某个节点的next元素指向在它前面出现过的节点，则表明该链表存在环路。
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    struct ListNode *fast = head;
    struct ListNode *low = head;
//这个地方跟141. 环形链表不太一样，这里快指针跟慢指针同时从头开始走。
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        low = low->next;
        if (fast == low) {
            break;
        }
    }
    if (fast==NULL || fast->next == NULL) {
        return NULL;
    }

    fast = head;
    while (fast != low) {
        fast = fast->next;
        low = low->next;
    }

    return fast;
//141的写法里快指针先走了一步，如果要使用141的写法，相遇后快指针回到头，慢指针要向前走一步
//    if (head == NULL || head->next == NULL) {
//        return NULL;
//    }
//
//    struct ListNode *fast = head->next;
//    struct ListNode *low = head;
//
//    while (fast != low) {
//        if (fast == NULL || fast->next == NULL) {
//            return NULL;
//        }
//        fast = fast->next->next;
//        low = low->next;
//    }
//    fast = head;
//    low = low->next;
//    while (fast != low) {
//        fast = fast->next;
//        low = low->next;
//    }
//
//    return fast;
}