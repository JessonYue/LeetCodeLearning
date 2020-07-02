/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int kthToLast(ListNode head, int k) {
        if (head == null || k < 0) {
            return -1;
        }
        ListNode fast = head;
        ListNode low = head;
        while(k != 0) {
            fast = fast.next;
            k--;
        }

        while(fast != null){
            fast = fast.next;
            low = low.next;
        }

        return low.val;
    }
}