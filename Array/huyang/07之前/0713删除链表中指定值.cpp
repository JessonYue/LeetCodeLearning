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
    ListNode* removeElements(ListNode* head, int val) {
               if(!head){
            return head;
        }

        ListNode* ret = head;


        while(head){
            if(head->val == val){
                ret = head->next;
                head = head->next;
            }else{
                break;
            }

        }


        while(head && head->next){
            if(head->next ->val == val){
                head->next  = head->next->next;
            }else{
                head = head->next;

            }

        }


        return ret;


    }
};