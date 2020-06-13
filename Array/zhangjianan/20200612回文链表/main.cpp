//
// Created by 张佳男 on 2020/6/12.
//

#include <iostream>
#include <cstring>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

  
bool isPalindrome(struct ListNode* head){
    int catch[70000];
        struct ListNode* newhead=head;
        int size=0;
        while(newhead){
              size++;
            catch[size]=newhead->val;
            newhead=newhead->next;
        }
    
        for(int i=1;i<=size/2;i++){
            if(catch[i]!=catch[size-i+1])return false;
        }
        return true;
}
odd->next=evenHead;
return head;
}
int main() {
    return 0;
}