/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head==NULL) return NULL;
    struct ListNode* oldHead=head;
    int n=1;
    while(oldHead->next!=NULL){
        oldHead=oldHead->next;
        n++;
    }
    oldHead->next=head;
      for(int i=0;i<n-k% n-1 ;i++){
head=head->next;
      }
      struct ListNode* newHead=head->next;
      head->next=NULL;
      return newHead;
}