package day47_0717;

import java.util.List;

public class day47_leetcode160 {


      public class ListNode {
      int val;
      ListNode next;
      ListNode(int x) {
          val = x;
          next = null;
      }
  }

    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
          ListNode p = headA;
          ListNode q = headB;

          while (p!=q){
              if (p!=null){
                  p = p.next;
              }else{
                  p = headB;
              }
              if(q!=null){
                  q = q.next;
              }else{
                  q  = headA;
              }
          }
          return p;
    }
}
