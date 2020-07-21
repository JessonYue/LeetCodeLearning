struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head == NULL) return NULL;
    int length;
    struct ListNode* tail = head;
    struct ListNode* new_tail = head;
    struct ListNode* new_head = head;
    for(length=1;tail->next!=NULL;length++) {
        tail = tail->next;
    }
    tail->next = head;
    for(int i=0;i<length-k%length-1;i++) {
        new_tail = new_tail->next;
    }
    new_head = new_tail->next;
    new_tail->next = NULL;
    return new_head;
}