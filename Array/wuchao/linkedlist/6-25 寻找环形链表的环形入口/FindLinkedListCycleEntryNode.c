//
// Created by 吴超 on 2020/6/25.
//

#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast!=NULL&&fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        //有环
        if(slow==fast){
            break;
        }
    }
    if(fast==NULL||fast->next==NULL){
        return NULL;
    }
    fast = head;
    while (slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

