//
// Created by 吴超 on 2020/6/26.
//
struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode *node) {
    struct ListNode *next = node->next;
    node->val = next->val;
    node->next = next->next;
    next->next = NULL;
    free(next);
}

