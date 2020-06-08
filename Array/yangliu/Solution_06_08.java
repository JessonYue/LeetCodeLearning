public class Solution_06_08 {
    public ListNode reverseList(ListNode head) {
        ListNode pre=null;
        ListNode current=head;
        while (current!=null){
            ListNode currentNext=current.next;
            current.next=pre;
            pre=current;
            current=currentNext;

        }
        return pre;
    }

    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }
}
