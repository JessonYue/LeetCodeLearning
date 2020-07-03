package day33;

public class day33_leetcode_interview0208 {
    class ListNode {
      int val;
      ListNode next;
      ListNode(int x) {
          val = x;
          next = null;
      }
    }

    public ListNode detectCycle(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;

        while (fast!=null){
            fast = fast.next;
            if(fast!=null){
                fast = fast.next;
                slow = slow.next;
            }

            if(fast == slow){
                break;
            }
        }

        if(fast != slow)
            return null;

        fast = head;
        while (fast!=slow){
            fast = fast.next;
            slow = slow.next;
        }

        return slow;
    }

}
