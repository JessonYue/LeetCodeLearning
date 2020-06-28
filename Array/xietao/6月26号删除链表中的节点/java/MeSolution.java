import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class MeSolution {

    static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    class Solution {
        public void deleteNode(ListNode node) {
            node.val = node.next.val;
            node.next= node.next.next;
        }
    }
}
