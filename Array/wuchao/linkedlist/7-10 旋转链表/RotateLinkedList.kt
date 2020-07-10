package com.slow.lib.practice.linkedList

/**
 * @Author wuchao
 * @Date 2020/7/10-9:57 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class RotateLinkedList {
    class ListNode(var `val`: Int) {
        var next: ListNode? = null
    }
    fun rotateRight(head: ListNode?, k: Int): ListNode? {
        if(head==null){
            return null
        }
        val dummy = ListNode(-1)
        dummy.next = head
        var slow = dummy
        var fast = dummy
        var length = 0
        while(slow.next!=null){
            slow = slow.next!!
            length++
        }
        slow = dummy
        var m = k%length
        while(m>0){
            fast = fast.next!!
            if(fast.next==null){
                fast = dummy
            }
            m--
        }
        while(fast.next!=null){
            slow = slow.next!!
            fast = fast.next!!
        }
        if(slow==fast){
            return head
        }
        val newHead = slow.next
        slow.next = null
        fast.next = head
        return newHead
    }
}