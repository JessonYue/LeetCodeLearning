package day24;

public class day24_leecode_141 {
    class ListNode {
      int val;
      ListNode next;
      ListNode(int x) {
          val = x;
          next = null;
      }
  }


    public boolean hasCycle(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;

        while (fast != null){
            fast = fast.next;
            if(fast != null){
                fast = fast.next;
            }
            if(fast == slow){
                return true;
            }

            slow = slow.next;
        }
        return false;
    }


}
