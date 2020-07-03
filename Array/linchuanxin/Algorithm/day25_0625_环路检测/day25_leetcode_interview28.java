package day25;


/**
 * Definition for singly-linked list.

 */





public class day25_leetcode_interview28 {
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

        while (fast != null){
            fast = fast.next;
            if(fast != null && slow!= null){
                fast = fast.next;
                slow =slow.next;
            }
            if(fast == slow){
                //有环
                break;
            }

        }
        // while (fast != null && slow != null) {
        //     if (fast.next == null) {
        //         return null;
        //     }
        //     fast = fast.next.next;
        //     slow = slow.next;
        //     if (slow == fast) {
        //         break;
        //     }
        // }
        if (fast != slow) return null;
        fast = head;
        while (fast != slow){
            fast = fast.next;
            slow = slow.next;
        }

        return slow;


    }
}
