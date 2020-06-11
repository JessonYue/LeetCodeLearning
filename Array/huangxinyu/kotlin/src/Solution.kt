import com.ryujin.algorithm.ListNode

class Solution {
    /**
     * 删除倒数第n个节点
     */
    fun removeNthFromEnd(listNode: ListNode?, n: Int): ListNode? {
        val preHead = ListNode(-1, listNode)
        var p1 = listNode
        var i = 0
        while (i < n) {
            assert(p1 != null)
            p1 = p1!!.next
            i++
        }
        var p2: ListNode? = preHead
        while (p1 != null) {
            p1 = p1.next
            p2 = p2!!.next
        }
        p2!!.next = p2.next!!.next
        return preHead.next
    }
    /**
     * 合并两个有序链表
     */
    fun mergeTwoLists(l1: ListNode?, l2: ListNode?): ListNode? {
        var l11 = l1;
        var l22 = l2;
        val preHead = ListNode(-1, l1)
        var pre = preHead
        while (l1 != null && l2 != null) {
            if (l11!!.value <= l22!!.value) {
                pre.next = l11
                l22 = l2.next
            }else{
                pre.next = l22
                l11 = l11.next
            }
            pre = pre.next!!
        }
        pre.next = l11 ?: l22;
        return preHead.next
    }
}