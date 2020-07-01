package com.withyang.lib;


/**
 * Created by CYLiu on 2020/6/30
 */
class Solution_6_30 {
    public static void main(String[] args) {

    }
    public TreeNode sortedListToBST(ListNode head) {
        if (head==null){
            return null;
        }
        ListNode tail=head;
        while (tail!=null){
            tail=tail.next;
        }
        return treeNode(head,tail);
    }
    private TreeNode treeNode(ListNode head, ListNode tail) {
        if(head==tail){
            return null;
        }
        ListNode node=findMidNode(head,tail);
        TreeNode root=new TreeNode(node.val);
        root.left=treeNode(head,node);
        root.right=treeNode(node.next,tail);
        return root;
    }
    private ListNode findMidNode(ListNode head, ListNode tail) {
        ListNode fast = head;
        ListNode slow = head;
        while (fast!=tail&&fast.next != tail) {
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }


    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }


    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

}
