/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {

        ListNode pre = null;
        
        ListNode curr = head;
        while(curr!=null){
            ListNode tmp = head.next;
            head.next =  pre;
            pre = tmp;
            curr = tmp;
        }

        return pre;
    }
}