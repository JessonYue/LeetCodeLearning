//
// Created by 吴超 on 2020/7/2.
//

#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *reverse(struct ListNode *prev, struct ListNode *current);

struct ListNode *reverseList(struct ListNode *head) {
    return reverse(NULL, head);
}

struct ListNode *reverse(struct ListNode *prev, struct ListNode *current) {
    if (current == NULL) {
        return prev;
    }
    struct ListNode *next = current->next;
    current->next = prev;
    return reverse(current, next);
}
