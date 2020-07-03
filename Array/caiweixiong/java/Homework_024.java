import java.util.ArrayList;
import java.util.List;

public class Homework_024 {

    void homework_024_109() {
        ListNode head = new ListNode(1);
        head.listInsert(head, 2);
        head.listInsert(head, 3);
        head.listInsert(head, 4);
        head.listInsert(head, 5);
        head.listInsert(head, 6);
        head.listInsert(head, 7);
        head.displayList(head);
        TreeNode treeRoot = sortedListToBST(head);
        treeRoot.displayTree(treeRoot);
    }

    private ListNode findMiddleElement(ListNode head) {
        ListNode prevPtr = null;
        ListNode slowPtr = head;
        ListNode fastPtr = head;

        while (fastPtr != null && fastPtr.next != null) {
            prevPtr = slowPtr;
            slowPtr = slowPtr.next;
            fastPtr = fastPtr.next.next;
        }

        if (prevPtr != null) {
            prevPtr.next = null;
        }   
        return slowPtr;
    }

    private TreeNode sortedListToBST(ListNode head) {    // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
        if (head == null) {
            return null;
        }

        ListNode mid = this.findMiddleElement(head);
        TreeNode node = new TreeNode(mid.val);

        if (head == mid) {
            return node;
        }
        node.left = this.sortedListToBST(head);
        node.right = this.sortedListToBST(mid.next);
        return node;
    }
}
