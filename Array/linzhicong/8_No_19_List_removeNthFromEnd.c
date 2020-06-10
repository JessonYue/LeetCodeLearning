/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(!head) return NULL;
    struct ListNode* first = head;// 先走的指针
    struct ListNode* last = head;// 后走的指针
    while(first) {
        if(n < 0) {
            last = last->next;
        }
        n--;
        first = first->next;
    }
    if(n == 0) { // 要删除的节点是头节点
        return head->next;
    }
    last->next = last->next->next;
    return head;
}