import java.security.PrivateKey;

public class Solution_06_24 {

    public boolean hasCycle(ListNode head) {
        ListNode fast=head;
        ListNode slow=head;
        while (fast!=null&&slow!=null){
          if(fast.next==null)return false;
           fast=fast.next.next;
           slow=slow.next;
           if (fast==slow)
               return true;

        }
        return false;
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
