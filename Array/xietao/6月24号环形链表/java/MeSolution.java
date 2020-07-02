import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class MeSolution {

    static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    public static class Solution {
        public boolean hasCycle(ListNode head) {
            if (head == null || head.next == null)
                return false;
            ListNode slow = head;
            ListNode fast = head.next;
            while (slow != fast) {
                if (head == null || head.next == null)
                    return false;
                slow = slow.next;
                fast = fast.next.next;
            }
            return true;
        }
    }
}
