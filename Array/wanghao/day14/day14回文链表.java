/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head == null){
            return true;
        }
        ListNode dummyNode = new ListNode(0);
        dummyNode.next = head;
        ListNode slow = dummyNode;
        ListNode fast = dummyNode;
        ListNode prev = null;
        while(fast != null && fast.next != null){
            fast = fast.next.next;
            ListNode temp = slow.next;
            slow.next = prev;
            prev = slow;
            slow = temp;
        }
        ListNode rigth;
        if(fast != null){
            if(slow.val != slow.next.val){
                return false;
            }
            rigth = slow.next.next;
        }
        else{
            rigth = slow.next;
        }
        while(prev != null && rigth != null){
            if(prev.val != rigth.val){
                return false;
            }
            prev = prev.next;
            rigth = rigth.next;
        }
        return true;
    }
}