package com.slow.lib.practice.linkedList

/**
 * @Author wuchao
 * @Date 2020/7/2-9:21 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class ReverseLinkedList {
    class ListNode(var `val`: Int) {
        var next: ListNode? = null
    }

    fun reverseList(head: ListNode?): ListNode? {
        return reverse(null, head)
    }

    fun reverse(prev: ListNode?, current: ListNode?): ListNode? {
        if (current == null) {
            return prev
        }
        val next = current.next
        current.next = prev
        return reverse(current, next)
    }
}