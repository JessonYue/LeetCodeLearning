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
    ListNode *detectCycle(ListNode *head) {
        if(!head){
            return head;
        }
        ListNode *f = head;
        ListNode *l = head;
        while(f && f->next){
            f = f->next->next;
            l = l->next;
            if(f == l){
                break;
            }
        }
        if(!f|| !f->next) return NULL;

        l = head;
        while(l){
            if(f->val == l->val){
                return f;
            }
            f = f->next;
            l = l->next;

        }
        return NULL;


    }
};