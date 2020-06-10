public class Solution_06_10 {

    public static ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode node = new ListNode(0);
        node.next = head;
        int count = 0;
        ListNode p = head;
        while (p != null) {
            count++;
            p = p.next;
        }
        p = node;
        for (int i = 0; i < count-n; i++) {
            p = p.next;
        }
        p.next = p.next.next;
        return node.next;
    }
    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }
}
