//
// Created by Vashon on 2020/8/10.
//

#ifndef HOMEWORK_HOMEWORK_007_H
#define HOMEWORK_HOMEWORK_007_H

#include "ListNode.h"

class Homework_007 {
private:
    // 方法一：头插法建链
    ListNode *reverseList_1(ListNode *head);

    // 方法二：递归
    ListNode *reverseList_2(ListNode *head);

public:
    // 反转链表，LeetCode第206题
    void homework_007_206();
};


#endif //HOMEWORK_HOMEWORK_007_H
