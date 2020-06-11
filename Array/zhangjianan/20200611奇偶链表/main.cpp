//
// Created by 张佳男 on 2020/6/10.
//

#include <iostream>
#include <cstring>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if(head==NULL)return NULL;
struct ListNode*  odd=head;//奇数
struct ListNode*  even=head->next;//偶数
struct ListNode*  evenHead=even;//偶数头
while(even!=NULL&&even->next!=NULL){
    odd->next=even->next;
    odd=even->next;
    even->next=odd->next;
    even=odd->next;
}
odd->next=evenHead;
return head;
}
int main() {
    return 0;
}