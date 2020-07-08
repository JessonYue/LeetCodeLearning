//
// Created by 谢涛 on 2020/6/30.
//
#include <stdio.h>
#include <stdlib.h>

  struct ListNode {
      int val;
      struct ListNode *next;
  };


int kthToLast(struct ListNode* head, int k){
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(k--){
        fast = fast->next;
    }
    while(fast != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    return slow->val;
}
int main() {

    return 0;
}