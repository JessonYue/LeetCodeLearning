package com.github.leetcode.p0328_odd_even_linked_list;

/**
 * https://leetcode-cn.com/problems/odd-even-linked-list
 * <p>
 * 328. 奇偶链表
 * 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
 * <p>
 * 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
 * <p>
 * 示例：
 * 输入: 1->2->3->4->5->NULL
 * 输出: 1->3->5->2->4->NULL
 * * <p>
 * 说明:
 * 应当保持奇数节点和偶数节点的相对顺序。
 * 链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。
 * <p>
 * 时间复杂度在 O()
 */
class Solution {

    //Definition for singly-linked list.
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
    /*
     执行用时 :1 ms, 在所有 Java 提交中击败了11.46%的用户
     内存消耗 :39.3 MB, 在所有 Java 提交中击败了8.70%的用户
     */
    public ListNode oddEvenList(ListNode head) {
        ListNode oddEvenList = new ListNode();
        ListNode odd = new ListNode();
        ListNode oddList = odd;
        ListNode even = new ListNode();
        ListNode evenList = even;

        int index = 0;
        while (head != null) {
            if (index % 2 == 0) {
                even.next = new ListNode(head.val);
                even = even.next;
            } else {
                odd.next = new ListNode(head.val);
                odd = odd.next;
            }
            head = head.next;
            index++;
        }

        even.next = oddList.next;
        oddEvenList.next = evenList.next;
        return oddEvenList.next;
    }

    //理解题目错了，把值当成奇偶了
/*    public ListNode oddEvenList(ListNode head) {
        if (head == null) {
            return null;
        }
        boolean isEven = head.val % 2 == 0;//判断首节点奇偶性

        ListNode oddEvenList = new ListNode();
        ListNode odd = new ListNode();
        ListNode oddList = odd;
        ListNode even = new ListNode();
        ListNode evenList = even;

        while (head != null) {
            if (head.val % 2 == 0) {
                even.next = new ListNode(head.val);
                even = even.next;
            } else {
                odd.next = new ListNode(head.val);
                odd = odd.next;
            }
            head = head.next;
        }
        *//*printList(oddList);
        printList(evenList);*//*
        if (isEven) {
            even.next = oddList.next;
            oddEvenList.next = evenList.next;
        } else {
            odd.next = evenList.next;
            oddEvenList.next = oddList.next;
        }
        return oddEvenList.next;
    }*/

    public static void main(String[] args) {
       /* ListNode listNode = new ListNode(1);
        listNode.next = new ListNode(2);
        listNode.next.next = new ListNode(3);
        listNode.next.next.next = new ListNode(4);
        listNode.next.next.next.next = new ListNode(5);*/
        ListNode listNode = new ListNode();
        /*listNode.next = new ListNode(1);
        listNode.next.next = new ListNode(3);
        listNode.next.next.next = new ListNode(5);
        listNode.next.next.next.next = new ListNode(6);
        listNode.next.next.next.next.next = new ListNode(4);
        listNode.next.next.next.next.next.next = new ListNode(7);*/

        printList(listNode);

        Solution solution = new Solution();
        ListNode oddEvenList = solution.oddEvenList(listNode);
        printList(oddEvenList);
    }

    private static void printList(ListNode listNode) {
        while (listNode != null) {
            System.out.printf(listNode.val + "->");
            listNode = listNode.next;
        }
        System.out.println();
    }

    /**
     * --------------------别人的代码--------------------
     */

}