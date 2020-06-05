package com.ryujin.algorithm

/**
 *
给定两个（单向）链表，判定它们是否相交并返回交点。请注意相交的定义基于节点的引用，而不是基于节点的值。
换句话说，如果一个链表的第k个节点与另一个链表的第j个节点是同一节点（引用完全相同），则这两个链表相交。
 */
class GetIntersectionNode {
    companion object {
        fun getIntersectionNode(headA: ListNode, headB: ListNode): ListNode? {
            var pa: ListNode? = headA
            var pb: ListNode? = headB
            while (pa != pb) {
                pa = if (pa == null) headB else headA.next
                pb = if (pb == null) headA else headB.next
            }
            return pa;
        }
    }
}