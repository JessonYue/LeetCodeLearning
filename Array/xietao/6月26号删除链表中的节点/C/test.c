//
// Created by 谢涛 on 2020/4/17.
//

#include <stdio.h>


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    *node = *(node->next);
}
 int main(){
}
