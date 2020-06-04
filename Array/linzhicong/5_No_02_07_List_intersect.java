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
        if(headA == null || headB == null) return null;
        ListNode a = headA;
        ListNode b = headB;
        /**
         * 思路：a+b的路径与b+a的路径相等；
         *      所以在第二遍的时候，
         *      如果有相交的点，则a==b的时候，就是该节点；
         *      如果没有相交的点，则a和b在第二遍跑完的时候，会同时为null，也满足 a==b 的条件，跳出循环，返回的a=null
         */
        while(a != b) {
            if(a != null) {
                a = a.next;
            } else {
                a = headB;
            }
            if(b != null) {
                b = b.next;
            } else {
                b = headA;
            }
        }
        return a;
    }
}