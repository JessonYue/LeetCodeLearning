package com.slow.lib.practice.linkedList;

/**
 * @Author wuchao
 * @Date 2020/6/24-9:26 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class LinkedListHasCycle {
    class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    public boolean hasCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
}
