package LInterview02_02;

import Base.ListNode;

public class Solution {






    public static int kthToLast2(ListNode head, int k) {
        int length = 0;
        ListNode cur = head;
        while (cur != null) {
            length++;
            cur = cur.next;
        }
        int count = length - k + 1;
        cur = head;
        length = 1;
        while (cur != null) {
            if (count == length) {
                return cur.val;
            }
            length++;
            cur = cur.next;
        }
        return 0;
    }

    public static int kthToLast3(ListNode head, int k) {
        ListNode pre = null;
        ListNode cur = head;
        while (cur != null) {
            ListNode curNext = cur.next;
            cur.next = pre;
            pre = cur;
            cur = curNext;
        }
        int i = 1;
        while (pre != null) {
            if (i == k) {
                return pre.val;
            }
            i++;
            pre = pre.next;
        }
        return 0;
    }
    private static int step = 1;
    /**
     * 在链表中找倒数第 k 个元素
     *
     * @param head
     * @param k
     * @return
     */
    public static int kthToLast4(ListNode head, int k) {
        if (head.next == null) return head.val;
        int val = kthToLast4(head.next, k);
        if (step++ >= k) {
            return val;
        }else {
            return head.val;
        }
    }


    public static void main(String[] args) {
        ListNode listNode1 = new ListNode(new int[]{1, 2, 3, 4, 5, 6});
        ListNode listNode2 = new ListNode(new int[]{1, 2, 3, 4, 5, 6});
//        kthToLast1(listNode1, 6);
        System.out.println(kthToLast2(listNode1, 6));

        System.out.println(kthToLast3(listNode1, 6));
        System.out.println(kthToLast4(listNode2, 6));
    }


}
