package L234;

import Base.ListNode;


/**
 * https://leetcode.com/problems/palindrome-linked-list/
 */

public class Solution {


    /**
     * 将复制到数组中后用双指针法
     * 1.将链表复制到数组
     * 2.用前后两个指针，一个指向数组头，一指向数组尾
     * 3.比较指针指向的元素是否相等，直到两个指针相遇
     *
     * @param head
     * @return
     */
    public static boolean isPalindrome1(ListNode head) {
        int length = 0;
        ListNode cur = head;
        while (cur != null) {
            length++;
            cur = cur.next;
        }
        cur = head;
        int[] intArray = new int[length];
        int index = 0;
        while (index < length) {
            intArray[index++] = cur.val;
            cur = cur.next;
        }
        int p = 0;
        int q = length - 1;
        while (p < q) {
            if (intArray[p] != intArray[q]) {
                return false;
            }
            p++;
            q--;
        }
        return true;


    }

    /**
     * 算法中的问题1：
     * 快慢指针找到中点
     * <p>
     * 算法中的问题1：
     * 递归链表：递归到底层，返回的时候就是反向的遍历
     * <p>
     * <p>
     * 找到链表中点 反转部分链表
     * 1.反转后半部分链表
     * 2.判断是否是回文
     *
     * @param head
     * @return
     */
    public static boolean isPalindrome2(ListNode head) {
        if (head == null) {
            return true;
        }
        int length = 0;
        ListNode cur = head;
        while (cur != null) {
            length++;
            cur = cur.next;
        }
        cur = head;
        int halfL = length / 2;
        for (int i = 0; i < halfL; i++) {
            cur = cur.next;
        }

        ListNode pre = null;
        ListNode next;
        while (cur != null) {
            next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }
        cur = head;
        for (int i = 0; i < halfL; i++) {
            if (cur.val != pre.val) {
                return false;
            }
            cur = cur.next;
            pre = pre.next;
        }
        return true;
    }

    /**
     * 判断链表回文
     * <p>
     * 竟然使用的是递归到底，按方法栈桢弹出时，保留的节点变量
     * 这时 链表竟然是你想访问的
     *
     * @param head
     * @return
     */
    public static boolean recursivelyCheck(ListNode head) {
        if (head != null) {
            if (!recursivelyCheck(head.next)) return false;
            if (head.val != first.val) {
                return false;
            }
            first = first.next;
        }
        return true;
    }

    private static ListNode first;

    public static boolean isPalindrome3(ListNode head) {
        first = head;
        return recursivelyCheck(head);
    }

    public static void main(String[] args) {
        ListNode listNode1 = new ListNode(1);
        ListNode listNode2 = new ListNode(1);
        ListNode listNode3 = new ListNode(2);
        ListNode listNode4 = new ListNode(1);


        listNode1.next = listNode2;
        listNode2.next = listNode3;
        listNode3.next = listNode4;
        boolean palindrome1 = isPalindrome1(listNode1);
        boolean palindrome2 = isPalindrome2(listNode1);
        boolean palindrome3 = isPalindrome3(listNode1);


        System.out.println(palindrome1);
        System.out.println(palindrome2);
        System.out.println(palindrome3);

    }


}
