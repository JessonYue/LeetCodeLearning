//
// Created by LCX on 2020/6/27.
//


  struct ListNode {
      int val;
      struct ListNode *next;
  };

void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}