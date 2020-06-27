package L206;

import DataStructure.ListNode;

public class Solution {

    public static ListNode reverseList1(ListNode head) {
        ListNode pre = null;
        ListNode cur = head;
        while (cur != null) {
            ListNode curNext = cur.next;
            cur.next = pre;
            pre = cur;
            cur = curNext;
        }
        return pre;
    }

//    public static ListNode reverseList2(ListNode head) {
//        if (head == null || head.next == null) {
//            return head;
//        }
//        ListNode h = head;
//        ListNode rehead = reverseList2(head.next);
//        rehead.next = h;
//        return
//    }


    public static void main(String[] args) {
        int[] arrays = new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9};
        ListNode listNode = new ListNode(arrays);
        System.out.println(listNode);
        System.out.println(reverseList1(listNode));
    }
}
