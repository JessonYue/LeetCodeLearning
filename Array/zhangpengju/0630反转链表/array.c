//
// Created by 张鹏举 on 2020-06-30.
//
struct ListNode* reverseList(struct ListNode* head){
   
    struct ListNode *res = NULL, *cur = head;
    while (cur){           
        head = head->next; 
        cur->next = res;    
        res = cur;          
        cur = head;        
    }
    return res;

}