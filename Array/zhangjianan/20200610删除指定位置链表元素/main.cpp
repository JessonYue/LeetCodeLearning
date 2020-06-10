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


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
        struct ListNode * newhead=(struct ListNode*)malloc(sizeof(struct ListNode));
        newhead->next=head;
        struct ListNode * first=newhead;
          struct ListNode * senccond=newhead;
          for(int i=0;i<n+1;i++){
              first=first->next;
          }
          while(first!=NULL){
               first=first->next;
                senccond=senccond->next;
          }
          senccond->next=senccond->next->next;
          return newhead->next;
}
int main() {
    return 0;
}