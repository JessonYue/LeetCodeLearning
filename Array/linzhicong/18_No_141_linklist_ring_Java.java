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
        if(head == null || head.next == null) return false;
        ListNode first = head;//慢指针
        ListNode last = head.next.next;//快指针
        while(first != null && last != null && last.next != null) {
            if(first == last) return true; // 当快指针追上慢指针，证明有环
            first = first.next;
            last = last.next.next;
        }
        return false;
    }
}