/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

    struct ListNode *pa,*pb;  //注意，别漏了struct
     pa = headA;
     pb = headB;
    
    while(pa!=pb){
        pa = (pa==NULL)? headB : pa->next;
        pb = (pb==NULL)? headA : pb->next;
    }
    return pa;
}

