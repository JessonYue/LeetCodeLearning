package L141;

import DataStructure.ListNode;

import java.util.HashSet;
import java.util.Set;

public class Solution {
    /**
     * @param head
     * @return
     */
    public boolean hasCycle1(ListNode head) {
        Set<ListNode> container = new HashSet<>();
        while (head != null) {
            if (container.contains(head)) {
                return true;
            } else {
                container.add(head);
            }
            head = head.next;
        }
        return false;
    }

    /**
     * 快慢指针可以起点不同
     *
     * @param head
     * @return
     */
    public boolean hasCycle2(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }

        ListNode slow = head;
        ListNode fast = head.next;

        while (slow != fast) {

            if (fast == null || fast.next == null) {
                return false;
            }
            slow = slow.next;
            fast = fast.next.next;
        }

        return true;
    }

    public static boolean hasCycle3(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (fast == slow) {
                return true;
            }
        }
        return false;
    }


    public static void main(String[] args) {
        ListNode listNode1 = new ListNode(3);
        ListNode listNode2 = new ListNode(2);
        ListNode listNode3 = new ListNode(0);
        ListNode listNode4 = new ListNode(-4);
        listNode1.next = listNode2;
        listNode2.next = listNode3;
        listNode3.next = listNode4;
        listNode4.next = listNode2;
        boolean b = hasCycle3(listNode1);
        System.out.println(b);
    }
}
