package com.example.myapplication;

import org.junit.Test;

public class DailyLeetCoding6_9 {

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

    @Test
    public void solution() {
        ListNode l1 = new ListNode(-9, new ListNode(3));
        ListNode l2 = new ListNode(5, new ListNode(7));

        ListNode l3 = mergeTwoLists(l1, l2);
        while (l3 != null) {
            System.out.println(l3.val);
            l3 = l3.next;
        }
    }

    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode node1 = l1;
        ListNode node2 = l2;
        ListNode newNode, head;
        if (null == node1) {
            return node2;
        }
        if (null == node2) {
            return node1;
        }
        if (node1.val < node2.val) {
            newNode = new ListNode(node1.val);
            node1 = node1.next;
        } else {
            newNode = new ListNode(node2.val);
            node2 = node2.next;
        }
        head = newNode;
        while (node1 != null && node2 != null) {
            if (node1.val < node2.val) {
                newNode.next = new ListNode(node1.val);
                node1 = node1.next;
            } else {
                newNode.next = new ListNode(node2.val);
                node2 = node2.next;
            }
            newNode = newNode.next;
        }
        while (node1 != null) {
            newNode.next = new ListNode(node1.val);
            node1 = node1.next;
            newNode = newNode.next;
        }
        while (node2 != null) {
            newNode.next = new ListNode(node2.val);
            newNode = newNode.next;
            node2 = node2.next;
        }
        return head;
    }
}
