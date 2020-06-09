/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *ha;
    struct ListNode *hb;
    ha = headA;
    hb = headB;
    while(ha != hb){
        ha =(ha != NULL) ? ha = ha -> next : headB;
        hb =(hb != NULL) ? hb = hb -> next : headA;
    }
    return hb;
}