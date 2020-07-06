//
// Created by linchuanxin on 2020/6/10.
//

#include <stdio.h>



 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;

        for (int i = 0; i < n + 1; ++i) {
            first = first->next;
        }

        while (first!= nullptr){
            first = first->next;
            second = second->next;
        }

        ListNode* delNode = second->next;    //找到要删除的节点
        second->next = delNode->next;   //second节点引用直接指向删除的下一个引用,牵手成功
        delete delNode;
        return dummy->next;

    }
};