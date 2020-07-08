package com.example.lsn37_dagger2_subcomponent;

/**
 * 109. 有序链表转换二叉搜索树
 * 别人的实例，还得再理解一下。
 */
public class Solution07_02 {

    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
            left = null;
            right = null;
        }
    }

    public TreeNode sortedListToBST(ListNode head) {

        if (head == null) {
            return null;
        }
        ListNode mid = findMid(head);
        TreeNode root = new TreeNode(mid.val);
        if (head == mid) {
            return root;
        }
        root.left = sortedListToBST(head);
        root.right = sortedListToBST(mid.next);
        return root;
    }

    private ListNode findMid(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode fast = head;
        ListNode low = head;
        ListNode pre = null;
        while (fast != null && fast.next != null) {
            pre = low;
            fast = fast.next.next;
            low = low.next;
        }

        if (pre != null) {
            pre.next = null;
        }
        return low;
    }

}
