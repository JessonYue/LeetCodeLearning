package com.slow.lib.practice.linkedList;

/**
 * 这个题之前做过，复习一遍，思路是建立两个指针，快慢指针，快指针先走k步，然后慢指针出发，当快指针走到链表尾部时，慢指针指向的就是倒数第k个元素了
 * 注意这里的快指针需要从哨兵节点开始走，而慢指针需要从head开始走，这样可以考虑到[1] 1 这种极端情况
 *
 * @Author wuchao
 * @Date 2020/7/1-9:17 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class FindKthToLast {
    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public int kthToLast(ListNode head, int k) {
        ListNode slow = head;
        ListNode fast = new ListNode(-1);
        fast.next = head;
        int i = 0;
        while (i < k) {
            fast = fast.next;
            i++;
        }
        while (fast.next != null) {
            slow = slow.next;
            fast = fast.next;
        }
        return slow.val;
    }
}
