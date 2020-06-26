import java.security.PrivateKey;

public class Solution_06_24 {

    public ListNode detectCycle(ListNode head) {
         ListNode fast=head;
        ListNode slow=head;
        while (fast!=null&&slow!=null){
          if (fast.next==null) return null;
           fast=fast.next.next;
           slow=slow.next;
           if (fast==slow){
               slow = head;
        while (slow != fast) {
            slow = slow.next;
            fast = fast.next;
        }
         return fast;
           }
        }
        return null;
    }


  class ListNode {
      int val;
      ListNode next;
     ListNode(int x) {
         val = x;
          next = null;
      }
  }

}
