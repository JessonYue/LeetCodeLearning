package day32;

public class day32_leetcode109 {



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

        private ListNode findMiddleElement(ListNode head) {
            ListNode pre = null;
            ListNode fast = head;
            ListNode slow = head;

            while (fast != null && fast.next!=null){
                pre = slow;
                slow = slow.next;
                fast = fast.next.next;
            }

            if(pre!=null){
                pre.next = null;
            }

            return slow;

        }
        public TreeNode sortedListToBST(ListNode head) {
            if(head==null)
                return null;
            ListNode midNode = findMiddleElement(head);
            TreeNode node = new TreeNode(midNode.val);
            if(head == midNode){
                return node;
            }
            node.left = sortedListToBST(head);
            node.right = sortedListToBST(midNode.next);
            return node;
        }
    }
}
