public class Solution_109 {
    ListNode getRoot(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        ListNode pre = null;
        while(fast != null && fast.next != null) {
            pre = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        if(pre != null) {
            pre.next = null;
        }
        return slow;
    }

    public TreeNode sortedListToBST(ListNode head) {
        if(head == null) return null;
        ListNode node = getRoot(head);
        TreeNode tree = new TreeNode(node.val);
        if(head == node) return tree;
        tree.left = sortedListToBST(head);
        tree.right = sortedListToBST(node.next);
        return tree;
    }
}
