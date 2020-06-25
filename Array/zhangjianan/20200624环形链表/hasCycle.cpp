/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 堆大小足够的话，操作系统malloc一般是向上生长的，如果链表有环的话，那么next的地址一般比当前地址小，所以：
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *p=head;
    while(p!=NULL&&p->next!=NULL){
        if(p->next<=p){
            return true;
        }
        p=p->next;
    }
     return false;
}