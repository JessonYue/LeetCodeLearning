package com.slow.lib.practice.linkedList;

/**
 * @Author wuchao
 * @Date 2020/7/19-10:49 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class FindIntersectionNode {
    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) return null;
        ListNode currentA = headA;
        ListNode currentB = headB;
        while (currentA != currentB) {
            currentA = currentA.next;
            currentB = currentB.next;
            if (currentA == null && currentB == null) {
                return null;
            }
            if (currentA == null) {
                currentA = headB;
            }
            if (currentB == null) {
                currentB = headA;
            }
        }
        return currentA;
    }
}
