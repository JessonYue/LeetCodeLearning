package com.slow.lib.practice.linkedList;

/**
 * 思路是快慢指针，他们的next都指向头结点，快指针先走k步，如果到尾部了，再重新指向头部。
 * 走完k步之后慢指针开始走，和快指针同时开始走，直到快指针到尾部。
 * 这个时候慢指针刚好是旋转过后的链表的尾部，因此从这里将链表断开，慢指针next指向null。
 * 将快指针next指向head(原链表的头部)即可。
 * 有一种特殊情况，即k等于链表的长度，经过这个旋转之后，链表并无变化，即慢指针等于快指针，直接返回头结点即可。
 * 由于k的值可能很大，可能远远大于链表长度，为了节省性能将m=k%length(链表长度)，只用走m步即可。
 * @Author wuchao
 * @Date 2020/7/10-9:46 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class RotateLinkedList {
    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) {
            return head;
        }
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode fast = dummy;
        ListNode slow = dummy;
        int length = 0;
        while (slow.next != null) {
            slow = slow.next;
            length++;
        }
        slow = dummy;
        k = k % length;
        while (k > 0) {
            fast = fast.next;
            if (fast.next == null) {
                fast = dummy;
            }
            k--;
        }
        while (fast.next != null) {
            slow = slow.next;
            fast = fast.next;
        }
        if (slow == fast) {
            return head;
        }
        ListNode newHead = slow.next;
        slow.next = null;
        fast.next = head;
        return newHead;
    }
}
