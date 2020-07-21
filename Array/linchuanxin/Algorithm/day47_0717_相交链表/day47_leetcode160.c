//
// Created by LCX on 2020/7/17.
//

#include <stdio.h>


  struct ListNode {
      int val;
      struct ListNode *next;
  };

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p = headA;
    struct ListNode *q = headB;

    while (p != q)
    {
        if(p!=NULL)
            p = p->next;
        else
            p = headB;
        if(q!=NULL)
            q = q->next;
        else
            q = headA;
    }

    return p;

}


int main(void)
{

}