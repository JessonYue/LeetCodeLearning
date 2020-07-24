/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
if(headA==NULL||headB==NULL) return NULL;
struct ListNode *h1=headA;
struct ListNode *h2=headB;
    while(h1!=h2){
        h1=((h1==NULL)?headB:h1->next);
        h2=((h2==NULL)?headA:h2->next);
    }
    return h2;
}