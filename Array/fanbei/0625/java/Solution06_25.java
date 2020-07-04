package com.example.lsn37_dagger2_subcomponent;

/**
 * 环路检测
 */
public class Solution06_25 {

    static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    public static class Solution {
        public ListNode detectCycle(ListNode head) {
            if (head == null || head.next == null) {
                return null;
            }
            ListNode fast = head;
            ListNode slow = head;
            while (fast != null && fast.next != null) {
                fast = fast.next.next;
                slow = slow.next;
                if (fast == slow) {
                    break;
                }
            }
            if (fast != slow) {
                return null;
            }
            fast = head;
            while (fast != slow) {
                fast = fast.next;
                slow = slow.next;
            }
            return fast;
        }
    }
}
