
//#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *sortList(struct ListNode *head) {
    // 归并排序
    int n = 0;
    // 走到null，刚好走链表的长度
    for (struct ListNode *i = head; i != NULL; i = i->next) n++;
    struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode));
    memset(dummy, 0, sizeof(struct ListNode));
    dummy->next = head;

    // 循环一下
    // 第一层循环，分块，从1个一块，2个一块，4个一块，直到n个一块，
    for (int i = 1; i < n; i = 2 * i) {
        struct ListNode *begin = dummy;
        // 开始归并
        // j + i < n 表示只有一段就不归并了，因为已经是排好序的
        for (int j = 0; j + i < n; j = j + 2 * i) {
            // 两块，找两块的起始节点
            // 开始都指向第一块的起点
            // 然后second走n步指向第二块的起点
            struct ListNode *first = begin->next, *second = first;
            for (int k = 0; k < i; k++) second = second->next;

            // 遍历第一块和第二块进行归并
            // 第一块的数量为i
            // 第二块的数量为i也可能小于i，所以循环条件要加一个second != null
            int f = 0, s = 0;
            while (f < i && s < i && second != NULL) {
                if (first->val < second->val) {
                    begin->next = first;
                    begin = begin->next;
                    first = first->next;
                    f++;
                } else {
                    begin->next = second;
                    begin = begin->next;
                    second = second->next;
                    s++;
                }
            }
            // 归并之后可能又多余的没有处理
            while (f < i) {
                begin->next = first;
                begin = begin->next;
                first = first->next;
                f++;

            }
            while (s < i && second != NULL) {
                begin->next = second;
                begin = begin->next;
                // second已经更新到下一块的起点了
                second = second->next;
                s++;
            }

            // 更新begin
            // begin.next 指向下一块的起点
            begin->next = second;
        }
    }
    return dummy->next;
}

