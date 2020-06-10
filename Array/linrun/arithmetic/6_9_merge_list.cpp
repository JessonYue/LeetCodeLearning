/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* firstNode = NULL;
    struct ListNode* pre = firstNode;
    struct ListNode* smaller = NULL;
    while(l1 != NULL && l2 != NULL){
        if(l1->val < l2->val){
            smaller = l1;
            l1 = l1 ->next;
        }else{
            smaller = l2;
            l2 = l2 ->next;
        }
        if(pre == NULL){
            firstNode = smaller;
        }else{
            pre->next = smaller;
        }
        pre = smaller;
    }
    while(l1 != NULL){
        smaller = l1;
        l1 = l1 ->next;
        if(pre == NULL){
            firstNode = smaller;
        }else{
            pre->next = smaller;
        }
        pre = smaller;
    }
    while(l2 != NULL){
        smaller = l2;
        l2 = l2 ->next;
        if(pre == NULL){
            firstNode = smaller;
        }else{
            pre->next = smaller;
        }
        pre = smaller;
    }
    return firstNode;

}
