
//最简洁的双指针，第一次使用c 写，参考了力扣。

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p = head, *q = head;
    while(p){
        if(n < 0){ q = q -> next; }       
        n--;
        p = p -> next;
    }
    if(n == 0){ return head -> next; }
    q -> next = q -> next -> next;
    return head;
}
