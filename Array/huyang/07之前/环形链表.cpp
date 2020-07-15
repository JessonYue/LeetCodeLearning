/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
         if(!head){
            return head;
        }
        ListNode *f = head;
        ListNode *l = head;
        while(f && f->next){
            f = f->next->next;
            l = l->next;
            if(f == l){
                return true;
            }
        }
        return false;
    }
};