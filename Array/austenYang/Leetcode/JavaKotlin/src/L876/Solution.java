package L876;

import Base.ListNode;

public class Solution {
    public ListNode middleNode1(ListNode head) {
        int ll = 0;
        ListNode cur = head;
        while (cur != null) {
            ll++;
            cur = cur.next;
        }
        int l = ll / 2;
        cur = head;

        while (l > 0) {
            cur = cur.next;
            l--;
        }

        return cur;
    }


    public ListNode middleNode2(ListNode head) {
        ListNode fast = head, slow = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
}

