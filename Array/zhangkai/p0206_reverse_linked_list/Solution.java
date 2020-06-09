package com.github.leetcode.p0206_reverse_linked_list;

import java.util.Stack;

/**
 * https://leetcode-cn.com/problems/reverse-linked-list/
 * <p>
 * 206. 反转链表
 * 反转一个单链表。
 * <p>
 * 示例：
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * <p>
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
 * <p>
 * 时间复杂度在 O(n^2)
 */
class Solution {
    //Definition for singly-linked list.
    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    /**
     * --------------------我的代码--------------------
     */
    /*
    方法一：使用栈先进先出的特性
        执行用时 :2 ms, 在所有 Java 提交中击败了5.97%的用户
        内存消耗 :39.5 MB, 在所有 Java 提交中击败了5.06%的用户
     */
    public ListNode reverseList(ListNode head) {
        if (head == null) {
            return null;
        }

        ListNode reverseList = new ListNode(0);
        Stack<Integer> stack = new Stack<>();
        while (head != null) {
            stack.push(head.val);
            head = head.next;
        }
        ListNode temp = reverseList;
        while (!stack.empty()) {
            temp.next = new ListNode(stack.pop());
            temp = temp.next;
        }
        return reverseList.next;
    }

    /*
    方法而：使用递归

     */

    public static void main(String[] args) {
        ListNode listNode = new ListNode(1);
        listNode.next = new ListNode(2);
        listNode.next.next = new ListNode(3);
        listNode.next.next.next = new ListNode(4);
        listNode.next.next.next.next = new ListNode(5);

        Solution solution = new Solution();
        ListNode reverseList = solution.reverseList(listNode);
        while (reverseList != null) {
            System.out.print(reverseList.val + " ");
            reverseList = reverseList.next;
        }
    }

    /**
     * --------------------别人的代码--------------------
     */

}