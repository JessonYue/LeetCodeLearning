package L203;

import Base.ListNode;

public class Solution {


    public static ListNode removeElements1(ListNode head, int val) {
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

    public static ListNode removeElements2(ListNode head, int val) {
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

    public static ListNode removeElements3(ListNode head, int val) {
        if (head == null) {
            return null;
        }
        ListNode result = removeElements3(head.next, val);
        if (head.val == val) {
            return result;
        } else {
            head.next = result;
            return head;
        }
    }

    public static ListNode removeElements4(ListNode head, int val) {
        if (head == null) {
            return null;
        }
        head.next = removeElements3(head.next, val);
        return head.val == val ? head.next : head;
    }

    public static void main(String[] args) {
        System.out.println(removeElements1(new ListNode(new int[]{1, 2, 6, 3, 4, 5, 6}), 6));
        System.out.println(removeElements2(new ListNode(new int[]{1, 2, 6, 3, 4, 5, 6}), 6));
        System.out.println(removeElements3(new ListNode(new int[]{1, 2, 6, 3, 4, 5, 6}), 6));
        System.out.println(removeElements4(new ListNode(new int[]{1, 2, 6, 3, 4, 5, 6}), 6));
    }


}
