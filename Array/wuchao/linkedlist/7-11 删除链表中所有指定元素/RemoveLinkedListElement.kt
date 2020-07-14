package com.slow.lib.practice.linkedList

/**
 * @Author wuchao
 * @Date 2020/7/11-9:16 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class RemoveLinkedListElement {
    class ListNode(var `val`: Int) {
        var next: ListNode? = null
    }

    fun removeElements(head: ListNode?, `val`: Int): ListNode? {
        var prev = ListNode(-1)
        prev.next = head
        var current = head
        var newHead = head
        while(current!=null){
            if(current.`val` == `val`){
                if(newHead==current){
                    newHead = newHead.next
                }
                prev.next = current.next
            } else {
                prev = prev.next!!
            }
            current = current.next!!
        }
        return newHead
    }
}