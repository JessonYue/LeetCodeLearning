package com.github.leetcode.p0021_merge_two_sorted_lists;

/**
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/
 * <p>
 * 合并两个有序链表：
 * 将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 * <p>
 * 示例：
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 * <p>
 * 时间复杂度在 O()
 */
class Solution {
    public static class ListNode {
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

    /**
     * --------------------我的代码--------------------
     */
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0, null);

        ListNode pre = head;
        while (l1 != null & l2 != null) {
            int p1 = l1.val;
            int p2 = l2.val;
            if (p1 < p2) {
                pre.next = new ListNode(p1, null);
                l1 = l1.next;
            } else {
                pre.next = new ListNode(p2, null);
                l2 = l2.next;
            }
            pre = pre.next;
        }
        //如果l1不为null
        while (l1 != null) {
            pre.next = l1;
            l1 = l1.next;
            pre = pre.next;
        }

        //如果l2不为null
        while (l2 != null) {
            pre.next = l2;
            l2 = l2.next;
            pre = pre.next;
        }

        return head.next;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        ListNode l1 = new ListNode(1, null);
        l1.next = new ListNode(2, null);
        l1.next.next = new ListNode(4, null);
        l1.next.next.next = new ListNode(7, null);

        ListNode l2 = new ListNode(1, null);
        l2.next = new ListNode(3, null);
        l2.next.next = new ListNode(4, null);
        l2.next.next.next = new ListNode(14, null);
        l2.next.next.next.next = new ListNode(24, null);

        print(l1);
        print(l2);

        ListNode listNode = solution.mergeTwoLists(l1, l2);
        print(listNode);

        System.out.println("----");
        ListNode listNode1 = solution.mergeTwoLists(null, null);
        print(l2);
        print(listNode1);
    }

    private static void print(ListNode listNode) {
        while (listNode != null) {
            System.out.print(listNode.val + "-->");
            listNode = listNode.next;
        }
        System.out.println();
    }

    /**
     * --------------------别人的代码--------------------
     */

}