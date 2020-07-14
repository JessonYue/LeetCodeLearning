package com.slow.lib.practice.linkedList;

/**
 * 删除链表中指定的所有节点
 * 前置指针prev从哨兵节点开始，当前指针current从头结点开始，再用一个newHead指针保存修改后的头结点的位置，从头结点开始
 * 遍历链表，直到current指针为空为止。如果current的值等于给定值时，将prev的next指针指向current的next元素，注意这时，prev不用前进，current前进一步
 * 当current 的值不等于给定值时，prev前进一步，current前进一步
 * 如果current的值等于newHead 的值，则代表头结点要删除了，newHead应该前进一步
 * 最后返回newHead
 * @Author wuchao
 * @Date 2020/7/11-9:07 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class RemoveLinkedListElement {
    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public ListNode removeElements(ListNode head, int val) {
        ListNode prev = new ListNode(-1);
        prev.next = head;
        ListNode current = head;
        ListNode newHead = head;
        while (current != null) {
            if (current.val == val) {
                if (current == newHead) {
                    newHead = newHead.next;
                }
                prev.next = current.next;
            } else {
                prev = prev.next;
            }
            current = current.next;
        }
        return newHead;
    }
}
