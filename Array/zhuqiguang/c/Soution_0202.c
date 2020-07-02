int kthToLast(struct ListNode* head, int k){
    struct ListNode* cur = head;
    for(int i=0;i<k;i++) {
        cur = cur->next;
    }
    while(cur != NULL) {
        head = head->next;
        cur = cur->next;
    }
    return head->val;
}