package com.example.myapplication;

import org.junit.Test;

public class DailyLeetCoding_6_12 {
    // 1,5,9,7,5,6,3,3,6,5,7,9,5,1

    public boolean isPalindrome(ListNode head) {
        //1. 快慢指针找中间位置
        //2. 翻转链表或者使用栈
        //3. 比较链表
        if (head == null || head.next == null) {
            return true;
        }

        ListNode slower = head, faster = head;
        while (faster.next != null && faster.next.next != null) {
            slower = slower.next;
            faster = faster.next.next;
        }
        if (slower.next == null) {
            return head.val == slower.val;
        }
        ListNode reversed = reverse(slower.next);

        while (reversed != null) {
            if (reversed.val != head.val) {
                return false;
            }
            reversed = reversed.next;
            head = head.next;
        }

        return true;
    }

    //1->2->3->4->5->6
    //6->5->4->3->2->1
    public ListNode reverse(ListNode node) {
        if (node.next == null) {
            return node;
        }
        ListNode pre = node;
        node = node.next;
        pre.next = null;
        ListNode next = node.next;
        while (node != null) {
            node.next = pre;
            pre = node;
            node = next;
            if (next != null)
                next = next.next;
        }
        return pre;
    }

    @Test
    public void testReverse() {
//        ListNode node = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6,new ListNode(6,new ListNode(5,new ListNode(4,new ListNode(3,new ListNode(2,new ListNode(1))))))))))));
        ListNode node = new ListNode(1, new ListNode(2));

        boolean result = isPalindrome(node);
        System.out.println(result);
    }

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
