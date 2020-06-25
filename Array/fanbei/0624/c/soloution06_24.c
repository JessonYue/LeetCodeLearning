#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }
    struct ListNode *fast = head->next;
    struct ListNode *low = head;
    while (fast != low) {
        if (fast == NULL || fast->next ==NULL) {
            return false;
        }
        fast = fast->next->next;
        low = low->next;
    }
    return true;
}

