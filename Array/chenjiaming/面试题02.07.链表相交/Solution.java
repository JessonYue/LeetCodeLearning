/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        //思路：双指针法。一个指针指向A链表，一个指向B链表。如果相遇则返回，否则没有交点。
        
        //如果存在相交结点，那么pA和pB一定会相遇。
        if(headA == null || headB == null)  return null;

        ListNode pA = headA,pB = headB;
        
        while(pA != pB){
			//当某链表的节点为空，说明到达结点，指向另外一个链表的头
            pA = pA == null ? headB : pA.next;
            pB = pB == null ? headA : pB.next;
        }

        return pA;
    }
}