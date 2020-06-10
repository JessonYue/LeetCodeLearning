package day10;

public class day10 {
    public class ListNode {
      int val;
      ListNode next;
      ListNode(int x) { val = x; }
  }

    /*
    *       n = 2;
    *     p q dump
    *        -1   --------->  1 -->  2 --> 3 --> 4 --> 5 --> null
    *
    *        dump
             second                       first
    *        -1   --------->  1 -->  2 --> 3 --> 4 --> 5 --> null
    *
    *                        second                  first
    *        -1   --------->  1 -->  2 --> 3 --> 4 --> 5 --> null
    *
    *                              second             first
    *        -1   --------->  1 -->  2 --> 3 --> 4 --> 5 --> null
    *
    *                                    second              first
    *        -1   --------->  1 -->  2 --> 3 --> 4 --> 5 --> null
    *
    *                                     second      first
    *        -1   --------->  1 -->  2 --> 3 --> 5 --> null
    *                                       ---> 4   remove
    * */

    public ListNode removeNthFromEnd_java(ListNode head, int n) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode first = dummy;
        ListNode second = dummy;

        for (int i = 0; i < n + 1; i++) {
            first = first.next;
        }

        while (first != null){
            first = first.next;
            second = second.next;
        }
        ListNode delNode = second.next;
        second.next = delNode.next;

        return dummy.next;
    }


}
