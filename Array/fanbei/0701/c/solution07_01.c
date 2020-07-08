#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int KthToLast(struct ListNode *head, int k) {

    if (head == NULL) {
        return -1;
    }
    struct ListNode *fast = head;
    struct ListNode *low = head;
    while (k != 0) {
        fast = fast->next;
        k--;
    }

    while (fast != NULL) {
        fast = fast->next;
        low = low->next;
    }
    return low->val;
}

