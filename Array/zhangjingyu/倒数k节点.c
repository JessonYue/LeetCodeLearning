
int kthToLast(struct ListNode* head, int k){
    struct ListNode* fast=head,*slow=head;

    while(fast){

        if(k>0){
            fast = fast->next;
            k--;
        }else{
            fast = fast->next;
            slow  = slow->next;
        }
    }
    return slow->val;
}