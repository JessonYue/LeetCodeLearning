/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){

        //去掉头
        //双指针,遍历cur，cur.next指向pre，然后cur和pre移动到下一个位置

        struct ListNode *curr ,*pre , *tmp ;
        pre = NULL;
        curr = head;


        while(curr != NULL){
            
            tmp  = curr->next;
            curr->next = pre;

            pre = curr;

            curr = tmp;
            

        }

        return pre;








}