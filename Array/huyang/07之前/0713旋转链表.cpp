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
    ListNode* rotateRight(ListNode* head, int k) {

 if(head == NULL || head->next==NULL){
        return head;
    }

    ListNode* start = head;
    ListNode* end = head;

    int n = 1 ;

    while(end->next != NULL ){
        n++;
        end = end->next;
    }
    end->next = start;
    int d = n -k%n-1;
    while(d){
        d--;
        start = start->next;
    }
    ListNode* ret = start->next;
    start->next = NULL;
    return ret;

        
    }
};