//
// Created by LCX on 2020/7/3.
//

#include <stdio.h>
#include <malloc.h>
struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head)
{
     struct ListNode *fast = head;
     struct ListNode *slow = head;

     while (fast != NULL)
     {
         fast = fast->next;
         if(fast != NULL)
         {
             fast = fast->next;
             slow = slow->next;
         }
         if (fast == slow)
             break;
     }

     if (fast != slow)
         return NULL;
     fast = head;
     while (fast != slow)
     {
         fast =fast->next;
         slow = slow->next;
     }

    return slow;

}