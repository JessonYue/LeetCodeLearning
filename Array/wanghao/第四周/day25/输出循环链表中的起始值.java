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
    public ListNode detectCycle(ListNode head) {
        Set <ListNode> answerSet = new HashSet<>();
        while(head != null){
            if(answerSet.contains(head)){
                return head;
            }else{
                answerSet.add(head);
            }
            head = head.next;
        }
        return null;
    }
}