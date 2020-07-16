struct ListNode* removeElements(struct ListNode* head, int val){
     struct ListNode *newHead = head;//链表头部
     
     struct ListNode *temp = head;//临时遍历变量
     struct ListNode *pre = NULL;//上一个节点
     while(temp){
         int value = temp->val;
         struct ListNode *next = temp->next;
         if(value == val){
             if(pre == NULL){
                 newHead = next;
                 pre = newHead;
                 temp->next = NULL;
             }else{
                pre->next = temp->next;
                temp->next = NULL;
             }

             temp = pre->next;
         }else{
            pre = temp;
           temp = temp->next;
         } 
       
     }

     return newHead;
}