//
// Created by LCX on 2020/6/24.
//

#include <stdio.h>
#include <stdbool.h>


 typedef struct ListNode {
      int val;
      struct ListNode *next;
 }Node;

bool hasCycle(Node *head) {
    Node *fast = head;
    Node *slow = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
        }
        if(fast == slow)
        {
            return true;
        }
        slow = slow->next;
    }

    return false;
}