public class day32 {

    class ListNode {
        int data;
        ListNode next;
    }

    class TreeNode {
        int data;
        TreeNode left;
        TreeNode right;
    }

    ListNode FindMidNode(ListNode head, ListNode pprev) {
        ListNode fast = head;
        ListNode slow = head;
        ListNode prev = null;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            prev = slow;
            slow = slow.next;
        }
        pprev = prev;
        return slow;
    }

    TreeNode sortedListToBST(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode left = null;
        ListNode midNode;
        ListNode right;
        midNode = FindMidNode(head, left);
        TreeNode root = null;
        if (root == null) {
            return null;
        }
        root.left = null;
        root.right = null;

        root.data = midNode.data;
        if (left != null) {
            left.next = null;
            root.left = sortedListToBST(head);
        }
        if (midNode.next != null) {
            root.right = sortedListToBST(midNode.next);
        }
        return root;
    }
}
