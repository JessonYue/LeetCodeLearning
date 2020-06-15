package com.lanfairy.md;

import java.util.ArrayList;
import java.util.ListIterator;
import java.util.PriorityQueue;

public class isPalindrome {
    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public boolean isPalindrome1(ListNode head) {

        int len = 0;
        ListNode current = head;
        while (current != null) {
            len++;
            current = current.next;
        }
        int[] invertedequence = new int[len];
        current = head;
        int i = len - 1;
        while (current != null) {
            invertedequence[i--] = current.val;
            current = current.next;
        }

        current = head;
        i = 0;
        boolean isPalindrome = true;
        while (current != null) {
            if (current.val != invertedequence[i])
                return false;
            current = current.next;
            i++;
        }
        return true;
    }

    /****************以下是参考题解的解法*********************/
    public boolean isPalindrome(ListNode head) {
        if (head == null) return true;//[] 空链表也是回文链表
        //链表的后半部分
        ListNode firstHalf = endOfFirstHalf(head);
        //反转后半部分
       ListNode secondHalf = reverseList(firstHalf.next);
        boolean isPalindrome = true;
        ListNode fir = head;
        ListNode sec = secondHalf;
        while (sec != null) {
            if (sec.val != fir.val){
                isPalindrome = false;
                break;
            }
            sec = sec.next;
            fir = fir.next;
        }
        firstHalf.next = reverseList(secondHalf);
        return isPalindrome;
    }

    //反转链表
    private ListNode reverseList(ListNode head) {
        ListNode pre = null;
        ListNode current = head;
        while (current != null) {
            ListNode temp = current.next;
            current.next = pre;
            pre = current;
            current = temp;
        }
        return pre;
    }

    //找出后半部分
    private ListNode endOfFirstHalf(ListNode head) {
        ListNode fast = head;  //
        ListNode slow = head;
        while (fast.next != null && fast.next.next != null) {
            fast = fast.next.next;//每次走两步
            slow = slow.next;//每次走一步
        }
        return slow;
    }


}
