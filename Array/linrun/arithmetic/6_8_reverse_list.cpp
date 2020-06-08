
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* pre = NULL;
    struct ListNode* current = head;
    struct ListNode* next = head == NULL?NULL:head->next;
    while(current != NULL){
        current -> next = pre;
        pre = current;
        current = next;
        next = next == NULL?NULL:next->next;
    }
    return pre;

}
