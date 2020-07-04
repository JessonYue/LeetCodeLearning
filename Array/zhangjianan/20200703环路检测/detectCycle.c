/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
      if(head==NULL||head->next==NULL) return NULL;
  struct ListNode *slow=head;
  struct ListNode *fast=head;
  while(fast!=NULL&&fast->next!=NULL
  ){
      fast=fast->next->next;
      slow=slow->next;
      if(
          slow==fast
      )break;
  }
  if(fast!=slow)return NULL;
  slow=head;
  while(slow!=fast){
      slow=slow->next;
      fast=fast->next;
  }
  return slow;
}