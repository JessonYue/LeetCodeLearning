/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    // if (head == null) return null;
    //     ListNode odd = head, even = head.next, evenHead = even;
    //     while (even != null && even.next != null) {
    //         odd.next = even.next;
    //         odd = odd.next;
    //         even.next = odd.next;
    //         even = even.next;
    //     }
    //     odd.next = evenHead;
    //     return head;
    if(head == NULL) return NULL;
    struct ListNode *old, *sec, *tmp;
    old = head;
    sec = head->next;
    tmp = sec;

    while(sec!=NULL && sec->next!=NULL ){
         old->next = sec->next;
         old = old->next;
         sec->next = old->next;
         sec = sec->next;   
    }
    old->next = tmp;
    return head;
}