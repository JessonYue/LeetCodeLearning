//
// Created by Vashon on 2020/8/11.
//

#ifndef HOMEWORK_HOMEWORK_008_H
#define HOMEWORK_HOMEWORK_008_H

#include "ListNode.h"

/**
    将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

    示例：
    输入：1->2->4, 1->3->4
    输出：1->1->2->3->4->4
 */

class Homework_008 {
private:
    // 方法一：归并
    ListNode *mergeTwoLists_1(ListNode *l1, ListNode *l2);

    // 方法二：递归
    ListNode *mergeTwoLists_2(ListNode *l1, ListNode *l2);

public:
    // 合并两个有序链表，LeetCode第21题
    void homework_008_021();
};


#endif //HOMEWORK_HOMEWORK_008_H
