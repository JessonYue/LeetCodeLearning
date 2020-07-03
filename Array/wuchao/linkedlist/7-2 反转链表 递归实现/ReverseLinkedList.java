package com.slow.lib.practice.linkedList;

/**
 * 反转链表，这次用递归求解
 * @Author wuchao
 * @Date 2020/7/2-9:16 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class ReverseLinkedList {

    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public ListNode reverseList(ListNode head) {
        return reverse(null, head);
    }

    public ListNode reverse(ListNode prev, ListNode current) {
        //当前节点为null，说明前置节点prev在链表尾部
        if (current == null) {
            return prev;
        }
        //用next指针保存下一个节点
        ListNode next = current.next;
        //当前节点的next指针指向上一个节点
        current.next = prev;
        //递归传递当前节点指针和下一个节点指针，作为下一次求解的前置节点和当前节点
        return reverse(current, next);
    }
}
