//
// Created by 谢涛 on 2020/6/30.
//
#include <stdio.h>
#include <stdlib.h>

  struct ListNode {
      int val;
      struct ListNode *next;
  };



struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* pre = NULL;
    struct ListNode* curr = head;
    while(curr != NULL){
        struct ListNode* temp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = temp;
    }
    return pre;
}
int main() {

    return 0;
}