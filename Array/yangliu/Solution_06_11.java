public class Solution_06_11 {
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode p=head;//记录奇数节点
        ListNode q=head.next;//记录偶数节点
        ListNode q1=head.next;
        while(p.next!=null&&q.next!=null){
            p.next=p.next.next;
            p=p.next;
            q.next=q.next.next;
            q=q.next;
        }
        p.next=q1;//最后一个奇数节点指向第一个偶数节点

        return head;
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
