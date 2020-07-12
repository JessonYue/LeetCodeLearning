package L109;

import Base.ListNode;
import Base.TreeNode;


public class Solution {
    public static TreeNode sortedListToBST(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode mid = findMiddleElement(head);
        TreeNode node = new TreeNode(mid.val);
        if (head == mid) {
            return node;
        }
        node.left = sortedListToBST(head);
        node.right = sortedListToBST(mid.next);
        return node;

    }

    private static ListNode findMiddleElement(ListNode head) {
        ListNode prePtr = null;
        ListNode slowPtr = head;
        ListNode fastPtr = head;

        while (fastPtr != null && fastPtr.next != null) {
            prePtr = slowPtr;
            slowPtr = slowPtr.next;
            fastPtr = fastPtr.next.next;
        }

        if (prePtr != null) {
            prePtr.next = null;
        }
        return slowPtr;
    }

    public static void main(String[] args) {
        ListNode listNode = new ListNode(new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9});
        TreeNode node = sortedListToBST(listNode);
        System.out.println(node);
    }


}
