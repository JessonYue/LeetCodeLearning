package com.example.listnode;

import java.util.Stack;

import sun.jvm.hotspot.debugger.linux.sparc.LinuxSPARCThreadContext;

public class Day2 {
    public static void main(String args[]) {
        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(3);
        node1.next = node2;
        node2.next = node3;
        ListNode node = reverseList(node1);
        while (node != null) {
            System.out.print(node.val + ",");
            node = node.next;
        }

    }

    static ListNode reverseList(ListNode head) {
        ListNode pre = null;
        ListNode cur = head;
        while (cur != null) {
            ListNode temp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = temp;
        }

        return pre;
    }
}
