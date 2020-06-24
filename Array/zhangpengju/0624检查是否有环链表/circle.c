/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    
    //采用快慢指针  追击问题

    struct ListNode *fast = head;
    struct ListNode *low = head;

    while(fast){
       if(fast->next == NULL)return false;
       
       fast = fast -> next -> next;
       low = low -> next;
       
       if(fast == low){
           return true;
       }

    }
    //快指针为null了，证明没有环

    return false;
}