package day11;

public class day11 {

  public class ListNode {
      int val;
      ListNode next;
      ListNode() {}
      ListNode(int val) { this.val = val; }
      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
  }

    class Solution {
        public ListNode oddEvenList(ListNode head) {
            //定义两个子链表，分别有虚拟节点
            ListNode dummy1 = new ListNode(-1);
            ListNode first = dummy1;
            ListNode dummy2 = new ListNode(-1);
            ListNode second = dummy2;
            int flag = 1;  //奇数
            while (head != null){
                //奇
                if(flag == 1){
                    first.next = head;
                    first = head;
                    head = head.next;
                    flag = 0;
                }else {
                    //偶
                    second.next = head;
                    second = head;
                    head = head.next;
                    flag = 1;
                }
            }
            first.next  = dummy2.next;
            second.next = null;
            return dummy1.next;
        }
    }
}
