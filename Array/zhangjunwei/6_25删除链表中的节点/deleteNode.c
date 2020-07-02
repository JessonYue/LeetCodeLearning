//
// Created by 张俊伟 on 2020/6/26.
//

struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}