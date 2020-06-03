package com.github.leetcode.p0002_add_two_numbers;


/**
 * https://leetcode-cn.com/problems/add-two-numbers/
 * <p>
 * 给出两个非空的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序的方式存储的，并且它们的每个节点只能存储一位数字。
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 您可以假设除了数字 0 之外，这两个数都不会以0开头。
 * <p>
 * 示例：
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 * <p>
 * 时间复杂度在 O()
 */
class Solution {
    /**
     * Definition for singly-linked list.
     */
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);//头节点不存放任何有意义的数值
        ListNode preNode = head;
        boolean isCarry = false;
        while (l1 != null && l2 != null) {
            int num = l1.val + l2.val;
            if (isCarry) {
                num++;
            }
            isCarry = num > 9;

            ListNode nextNode = new ListNode(num % 10);
            /*if (isCarry) {
                nextNode = new ListNode(num % 10);
            } else {
                nextNode = new ListNode(num);
            }*/
            preNode.next = nextNode;
            preNode = nextNode;

            l1 = l1.next;
            l2 = l2.next;
        }

        while (l1 != null) {
            int num = l1.val;
            if (isCarry) {
                num++;
            }
            isCarry = num > 9;

            ListNode nextNode = new ListNode(num % 10);
            preNode.next = nextNode;
            preNode = nextNode;
            l1 = l1.next;
        }

        while (l2 != null) {

            int num = l2.val;
            if (isCarry) {
                num++;
            }
            isCarry = num > 9;

            ListNode nextNode = new ListNode(num % 10);
            preNode.next = nextNode;
            preNode = nextNode;
            l2 = l2.next;
        }

        if (isCarry) {
            preNode.next = new ListNode(1);
        }

        return head.next;
    }

    //失败例子
    public ListNode addTwoNumbersFail(ListNode l1, ListNode l2) {
        StringBuilder sbl1 = new StringBuilder();
        while (l1 != null) {
            int val = l1.val;
            sbl1.append(val);
            l1 = l1.next;
        }
        int i1 = Integer.parseInt(sbl1.reverse().toString());

        StringBuilder sbl2 = new StringBuilder();
        while (l2 != null) {
            int val = l2.val;
            sbl2.append(val);
            l2 = l2.next;
        }
        int i2 = Integer.parseInt(sbl2.reverse().toString());//java.lang.NumberFormatException: For input string: "9999999991"


        int sum = i1 + i2;

        StringBuilder stringBuilder = new StringBuilder();
        String result = stringBuilder.append(sum).reverse().toString();
        ListNode head = null;
        ListNode pre = null;
        char[] chars = result.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if (i == 0) {
                head = new ListNode(Integer.parseInt(chars[i] + ""));
                pre = head;
            } else {
                ListNode node = new ListNode(Integer.parseInt(chars[i] + ""));
                pre.next = node;
                pre = node;
            }
        }

        return head;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        //2--4--3
        ListNode firstList = new ListNode(9);
        firstList.next = new ListNode(6);
        firstList.next.next = new ListNode(7);

        ListNode secondList = new ListNode(5);
        secondList.next = new ListNode(6);
        secondList.next.next = new ListNode(4);
        secondList.next.next.next = new ListNode(9);

        print(firstList);
        print(secondList);

        ListNode listNode = solution.addTwoNumbers(firstList, secondList);
        print(listNode);
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