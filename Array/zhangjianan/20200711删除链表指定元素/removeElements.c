/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    //哨兵节点,置于链表头之前
struct ListNode *swap = malloc(sizeof(struct ListNode));
swap->next=head;
      if(head==NULL) return NULL;
        struct ListNode* cur=head;
        struct ListNode* pre=swap;
        while(cur!=NULL){
           if(cur->val==val){
               pre->next=cur->next;
           }else pre=cur;
           cur=cur->next;
        }
        head = swap->next;
        free(swap);  //判断完毕，释放哨兵节点
        return head;
}