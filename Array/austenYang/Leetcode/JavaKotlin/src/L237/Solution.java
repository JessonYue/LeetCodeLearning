package L237;

import Base.ListNode;

public class Solution {
    public static void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }

    public static void main(String[] args) {
        int[] arrays = new int[]{12, 3, 4, 5, 6};
        ListNode listNode = new ListNode(arrays);
        ListNode nodeFromIndex = listNode.getNodeFromIndex(1);
        deleteNode(nodeFromIndex);
        System.out.println(listNode);
    }
}
