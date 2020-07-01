/**
 * date:2020/7/1
 * description:
 * author:rlin
 */
class M7_1_OrderLinkedListToBST {
    /**
     * Definition for singly-linked list.
     * public class ListNode {
     *     int val;
     *     ListNode next;
     *     ListNode(int x) { val = x; }
     * }
     */
    /**
     * Definition for a binary tree node.
     * public class TreeNode {
     *     int val;
     *     TreeNode left;
     *     TreeNode right;
     *     TreeNode(int x) { val = x; }
     * }
     */
    class Solution {
        private ListNode listNode;
        public TreeNode sortedListToBST(ListNode head) {
            int count = 0;
            ListNode current = head;
            listNode = head;
            while(current != null){
                current = current.next;
                count++;
            }
            return getTreeNode(0, count-1);
        }

        public TreeNode getTreeNode(int left, int right){
            if(left>right){
                return null;
            }
            int mid = (left+ right +1)/2;
            TreeNode l = getTreeNode(left, mid-1);
            TreeNode current = new TreeNode(listNode.val);
            current.left = l;
            listNode = listNode.next;
            current.right = getTreeNode(mid+1, right);
            return current;
        }
    }
}
