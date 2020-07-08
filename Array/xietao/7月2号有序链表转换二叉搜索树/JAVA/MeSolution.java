import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class MeSolution {


      public class ListNode {
          int val;
          ListNode next;
          ListNode(int x) { val = x; }
      }


      public class TreeNode {
          int val;
          TreeNode left;
          TreeNode right;
          TreeNode(int x) { val = x; }
      }

    class Solution {
        private ListNode finMiddleElement(ListNode head){
            ListNode prevPtr = null;
            ListNode fast = head;
            ListNode slow = head;
            while(fast != null && fast.next != null){
                prevPtr = slow;
                slow = slow.next;
                fast = fast.next.next;
            }
            if(prevPtr != null){
                prevPtr.next = null;
            }

            return slow;
        }

        public TreeNode sortedListToBST(ListNode head) {
            if(head == null){
                return null;
            }
            ListNode mid = this.finMiddleElement(head);
            TreeNode node = new TreeNode(mid.val);
            if(head == mid){
                return node;
            }
            node.left = this.sortedListToBST(head);
            node.right = this.sortedListToBST(mid.next);
            return node;
        }
    }
}
