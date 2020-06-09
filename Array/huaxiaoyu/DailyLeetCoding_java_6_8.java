package com.example.myapplication;

import org.junit.Test;

public class DailyLeetCoding_java_6_8 {
    //Reverse a singly linked list.
//Example:
//Input: 1->2->3->4->5->NULL     1->null 2->3->4->5 ;2->1 3->4->5
//Output: 5->4->3->2->1->NULL.
    class ListNode {
        int val;
        ListNode next;

        ListNode() {
            val = 0;
            next = null;
        }

        ListNode(int x) {
            val = x;
            next = null;
        }

        ListNode(int x, ListNode next) {
            val = x;
            this.next = next;
        }
    }

    public ListNode reverseList(ListNode head) {
        ListNode current = head;
        ListNode next = current.next;
        ListNode pre = null;
        while (next != null) {  // 4->3->2->1->NULL 5->null
            next = current.next;            //记录next
            current.next = pre;             //断开current重新指向pre
            pre = current;                  //current变pre
            current = next;                 //current++
        }
        return pre;
    }

    @Test
    public void test() {
        ListNode origin = new ListNode(1
                , new ListNode(2
                , new ListNode(3
                , new ListNode(4
                , new ListNode(5)))));

        ListNode next = origin;
        while (next != null) {
            System.out.println(next.val);
            next = next.next;
        }
        System.out.println("---");

        ListNode node = reverseList(origin);
        while (node != null) {
            System.out.println(node.val);
            node = node.next;
        }
    }
}
