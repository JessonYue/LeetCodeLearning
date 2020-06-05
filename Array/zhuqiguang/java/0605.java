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
 * 发现刷题重在思路，这道题首先要确定“链表相交”的概念，链表A和链表B相交与D，那么从D往后的链表都是相同的，
 * 因为他们共用的next指针，假定两个指针分别指向两个链表的头结点，链表A指针从头走到尾，然后再从链表B头开始走，相同的速度，
 * 相同的路径，所以两个链表会相遇
 */
//public class Solution {
//    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
//        if(headA == null || headB == null) return null;
//        ListNode nodeA = headA;
//        ListNode nodeB = headB;
//        while(nodeA != nodeB) {
//            nodeA =  nodeA == null ? headB : nodeA.next;
//            nodeB =  nodeB == null ? headA : nodeB.next;
//        }
//        return nodeA;
//    }
//}