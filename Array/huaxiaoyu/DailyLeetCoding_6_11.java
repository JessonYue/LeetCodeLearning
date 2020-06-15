package com.example.myapplication;

import org.junit.Test;

public class DailyLeetCoding_6_11 {
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

    //Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
    //You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
    //Example 1:
    //Input: 1->2->3->4->5->NULL
    //Output: 1->3->5->2->4->NULL
    //Example 2:
    //
    //Input: 2->1->3->5->6->4->7->NULL
    //Output: 2->3->6->7->1->5->4->NULL
    //1,2,3,4,5,6   1->3->2->4->5->6
    //1,3,5,2,4,6
    public ListNode oddEvenList(ListNode head) {
        ListNode insertNode = head;
        ListNode cursor = head;
        ListNode cPre;
        ListNode temp;
        int i = 1;
        while (cursor != null) {
            cPre = cursor;
            cursor = cursor.next;
            i++;
            if (i % 2 == 1 && null != cursor) {
                //奇数移位
                cPre.next = cursor.next;
                temp = insertNode.next;
                insertNode.next = cursor;
                cursor.next = temp;
                insertNode = insertNode.next;
                cursor = cPre;
            }
        }
        return head;
    }

    @Test
    public void test() {
        ListNode node = new ListNode(1);
        ListNode head = oddEvenList(node);
        while (head != null) {
            System.out.println(head.val);
            head = head.next;
        }
    }
}
