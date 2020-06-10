/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(!l1) return l2;
    if(!l2) return l1;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* temp = head;
    while(l1 && l2) {
        if(l1->val > l2->val) {
            temp->next = l2;
            l2 = l2->next;
        } else {
            temp->next = l1;
            l1 = l1->next;
        }
        temp = temp->next;
    }
    if(l1) {
        temp->next = l1;
    } else if(l2) {
        temp->next = l2;
    }
    return head->next;
}