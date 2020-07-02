package com.example.admin.myapplication.link;

/**
 * create by yx
 * on 2020/6/24
 */
public class SolutionLink {
    class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    /**
     * 141链表是否有环
     */
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }

        ListNode fast = head.next;
        ListNode low = head;
        while (fast != low) {
            if (fast == null || fast.next == null) {
                return false;
            }
            fast = fast.next.next;
            low = low.next;
        }
        return true;
    }

    /**
     * 面试题 02.08. 环路检测
     * 给定一个有环链表，实现一个算法返回环路的开头节点。
     * 有环链表的定义：在链表中某个节点的next元素指向在它前面出现过的节点，则表明该链表存在环路。
     */
    public ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null) {
            return null;
        }

        ListNode fast = head.next;
        ListNode low = head;
        while (fast != low) {
            if (fast == null || fast.next == null) {
                return null;
            }
            fast = fast.next.next;
            low = low.next;
        }

        fast = head;
        low = low.next;
        while (fast != low) {
            fast = fast.next;
            low = low.next;
        }
        return fast;
    }

    /**
     * 反转单链表
     */
    public ListNode reverseList(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode newHead = null;
        ListNode next = head;
        ListNode tmp = null;
        while (next != null) {
            tmp = next.next;
            next.next = newHead;
            newHead = next;
            next = tmp;
        }
        return newHead;
    }


    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    /**
     * 109. 有序链表转换二叉搜索树
     * 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
     * <p>
     * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
     */
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
