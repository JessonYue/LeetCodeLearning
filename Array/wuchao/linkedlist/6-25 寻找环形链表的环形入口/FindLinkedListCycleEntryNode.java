package com.slow.lib.practice.linkedList;

/**
 * @Author wuchao
 * @Date 2020/6/25-5:30 PM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class FindLinkedListCycleEntryNode {

    class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    //走到入口时，slow指针的步数，k = a + nb
    //第一次相遇时，slow = s ,fast = 2s , fast = s+nb, b为环的步数，即fast指针比slow指针多走nb个步数
    //第一次相遇时，slow = nb ,再走a步就可以到入口，但是a不知道，这时如果有一个指针从链表头开始走，走a步也会到入口
    //也就是说这两个指针会相遇，相遇时刚好走a步，相遇的这个点就是入口
    public ListNode detectCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {//有环
                break;
            }
        }
        if (fast == null || fast.next == null) {
            return null;
        }
        fast = head;
        while (slow != fast) {
            slow = slow.next;
            fast = fast.next;
        }
        return slow;
    }
}
