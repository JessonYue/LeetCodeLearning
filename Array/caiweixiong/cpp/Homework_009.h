//
// Created by Vashon on 2020/8/11.
//

#ifndef HOMEWORK_HOMEWORK_009_H
#define HOMEWORK_HOMEWORK_009_H

#include "ListNode.h"

/**
    给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

    示例：
    给定一个链表: 1->2->3->4->5, 和 n = 2.
    当删除了倒数第二个节点后，链表变为 1->2->3->5.

    说明：
    给定的 n 保证是有效的。

    进阶：
    你能尝试使用一趟扫描实现吗？
 */

class Homework_009 {
private:
    // 方法一：快慢指针
    ListNode *removeNthFromEnd_1(ListNode *head, int n);

public:
    // 删除链表的倒数第N个节点，LeetCode第19题
    void homework_009_019();
};


#endif //HOMEWORK_HOMEWORK_009_H
