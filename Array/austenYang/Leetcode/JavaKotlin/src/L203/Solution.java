package L203;

import DataStructure.ListNode;

public class Solution {


    public ListNode removeElements1(ListNode head, int val) {
        ListNode header = head;
        ListNode cur = head;
        ListNode pre = null;
        while (cur != null) {

            if (cur.val == val) {
                if (cur == header) {
                    header = cur.next;
                    pre = header;
                } else {
                    pre.next = cur.next;
                }
            } else {
                pre = cur;
            }
            cur = cur.next;
        }

        return header;
    }

    public ListNode removeElements2(ListNode head, int val) {
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;
        ListNode pre = dummyHead;
        ListNode cur = head;
        while (cur != null) {
            if (cur.val == val) {
                pre.next = cur.next;
            } else {
                pre = cur;
            }
            cur = cur.next;
        }
        return dummyHead.next;
    }
}
