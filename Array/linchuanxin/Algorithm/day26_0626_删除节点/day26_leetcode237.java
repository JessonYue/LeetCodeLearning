package day26;

public class day26_leetcode237 {

    public class ListNode {
         int val;
        ListNode next;
        ListNode(int x) { val = x; }
 }

    class Solution {
        public void deleteNode(ListNode node) {
            node.val = node.next.val;
            node.next = node.next.next;
        }
    }
}
