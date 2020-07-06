import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class MeSolution {

    
      public class ListNode {
          int val;
          ListNode next;
        ListNode(int x) { val = x; }
      }

    class Solution {
        public int kthToLast(ListNode head, int k) {
            ListNode p = head;
            while(k-- > 0){
                p = p.next;
            }

            while(p != null){
                p = p.next;
                head = head.next;
            }
            return head.val;
        }
    }
}
