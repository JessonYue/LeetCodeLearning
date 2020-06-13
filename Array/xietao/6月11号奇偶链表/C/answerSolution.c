//
// Created by 谢涛 on 2020/6/3.
//

#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* oddEvenList(struct ListNode* head){
    struct ListNode* odd = head;
    struct ListNode* evenHead = head->next;
    struct ListNode* even = head->next;
    while(even != NULL && even -> next != NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;

    return head;
}






