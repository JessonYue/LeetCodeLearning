//
// Created by LCX on 2020/6/26.
//
#include <stdio.h>


struct ListNode {
      int val;
      struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if(fast !=NULL && slow != NULL)
        {
            fast =fast->next;
            slow = slow->next;
        }
        if(fast == slow)
        {
            //有环
            break;
        }
    }

    if(fast != slow)
        return NULL;
    fast = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return fast;

}