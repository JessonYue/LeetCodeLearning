//
// Created by austenYang on 2020/7/25.
//

#include <stdio.h>
#include <mm_malloc.h>
#include "../Base/datastruct.h"

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *p = l1, *q = l2;
    struct ListNode *dummyHead = (struct ListNode *) malloc(sizeof(struct ListNode));
    dummyHead->next = NULL;
    struct ListNode *cur = dummyHead;

    int carry = 0;
    while (p != NULL || q != NULL) {
        int x = (p != NULL) ? p->val : 0;
        int y = (q != NULL) ? q->val : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        struct ListNode *newNode = (struct ListNode *) malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        cur->next = newNode;
        cur = cur->next;
        if (p != NULL) p = p->next;
        if (q != NULL) q = q->next;
    }

    if (carry > 0){
        struct ListNode *newNode = (struct ListNode *) malloc(sizeof(struct ListNode));
        newNode->val = carry;
        newNode->next = NULL;
        cur->next = newNode;
    }
    return dummyHead->next;

}

int main() {

    return 0;
}