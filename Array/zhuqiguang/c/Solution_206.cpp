/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *tmp = NULL;
    struct ListNode *pre = NULL;
    struct ListNode *cur = head;
    while(cur != NULL) {
        tmp = cur ->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}