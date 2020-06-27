package com.lanfairy.md.queue;

class ListNode {
      int val;
      ListNode next;
      ListNode(int x) {
          val = x;
          next = null;
      }
 }
public class hasCycle_6_24 {

    public boolean hasCycle1(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while (slow!=null && fast!=null && fast.next!=null){
            slow=slow.next;
            fast= fast.next.next;
            if (slow==fast)
                return true;
        }
        return false;
    }

}
