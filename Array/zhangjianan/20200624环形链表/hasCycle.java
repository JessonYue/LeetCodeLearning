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
 慢指针走一步，快指针走两步，相当于一个在原地不动，一个一次一步，如果有环的话，终究能走回原点；如果快指针比慢指针>=2步的时候，不能保证一定能走回环的起点。
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head==null||head.next==null) return false;
        ListNode slow=head;
        ListNode fast=head.next;
        while(slow!=fast){
            if(fast==null||fast.next==null) return false;
            slow=slow.next;
            fast=fast.next.next;
        }
        return true;
    }
}