相交链表
编写一个程序，找到两个单链表相交的起始节点。

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
    }
};

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

	        if(!headA || !headB) return NULL;

        int la=0 , lb= 0 ;
        ListNode *a = headA;
        ListNode *b = headB;

        while(a){
            a = a->next;
            la++;
        }
        while(b){
            b = b->next;
            lb++;
        }     
        if(la>lb){
            for(int i=0;i<(la-lb);++i)
                headA=headA->next;
        }
        if(la<lb){
            for(int j=0;j<(lb-la);++j)
                headB=headB->next;        }

        while(headA){
            if(headA == headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;







    }
};