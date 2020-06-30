/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head == null || head.next ==  null){
            return false;
        }
        ListNode first = head;
        ListNode second = head.next;
        while(first != second){
            if(second == null || second.next == null){
                return false;
            }
            first = first.next;
            second = second.next.next;
        }
        return true;
    }
}