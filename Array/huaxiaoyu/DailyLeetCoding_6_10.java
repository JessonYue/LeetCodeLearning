package com.example.myapplication;

import org.junit.Test;

public class DailyLeetCoding_6_10 {
    //Given a linked list, remove the n-th node from the end of list and return its head.
    //Example:
    //Given linked list: 1->2->3->4->5, and n = 2.
    //After removing the second node from the end, the linked list becomes 1->2->3->5.
    //Note:
    //Given n will always be valid.
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode reverseHead = reverse(head);
        ListNode cursor = reverseHead;
        ListNode pre = null;
        for (int j = 0; j < n; j++) {
            if (j == n - 1) {
                if (pre != null) {
                    pre.next = cursor.next;
                } else {
                    reverseHead = reverseHead.next;
                }
            } else {
                pre = cursor;
                cursor = cursor.next;
            }
        }
        ListNode newHead = reverse(reverseHead);
        return newHead;
    }

    private ListNode reverse(ListNode head) {
        if (null == head) {
            return null;
        }
        ListNode pre = null;
        ListNode current = head;
        ListNode next = current.next;
        while (current != null) {
            current.next = pre;
            pre = current;
            current = next;
            if (next != null) {
                next = next.next;
            }
        }
        return pre;
    }

    @Test
    public void main() {
        ListNode node = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
        ListNode reverseNode = removeNthFromEnd(node, 3);
        while (reverseNode != null) {
            System.out.println(reverseNode.val);
            reverseNode = reverseNode.next;
        }
    }

    //      Definition for singly-linked list.
    public class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }
}
