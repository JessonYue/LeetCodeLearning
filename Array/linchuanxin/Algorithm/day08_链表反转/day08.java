package day08;

public class day08 {

    public ListNode reverseList(ListNode head) {
        ListNode pre = null;
        ListNode cur = head;
        while (cur != null){
            ListNode tmp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = tmp;

        }
        return pre;
    }


    class ListNode {
          int val;
          ListNode next;
          ListNode(int x) { val = x; }
      }
}
