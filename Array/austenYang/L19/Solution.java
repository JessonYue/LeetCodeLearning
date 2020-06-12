package L19;

import DataStructure.ListNode;

public class Solution {

    /**
     * 同步法
     *
     * @param head
     * @param n
     * @return
     */
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;

        ListNode s = dummyHead, e = dummyHead;
        while (n > 0) {
            s = s.next;
            n--;
        }

        while (s.next != null) {
            s = s.next;
            e = e.next;
        }

        e.next = e.next.next;
        return dummyHead.next;


    }
}
