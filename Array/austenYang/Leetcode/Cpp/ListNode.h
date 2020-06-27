//
// Created by austenYang on 2020/6/27.
//

#ifndef CPP_LISTNODE_H
#define CPP_LISTNODE_H

#include <cstdlib>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {

    }
};

#endif //CPP_LISTNODE_H
