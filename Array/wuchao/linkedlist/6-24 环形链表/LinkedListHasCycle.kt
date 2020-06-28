package com.slow.lib.practice.linkedList

/**
 * @Author wuchao
 * @Date 2020/6/24-9:27 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class LinkedListHasCycle {
    class ListNode(var `val`: Int) {
        var next: ListNode? = null
    }

    fun hasCycle(head: ListNode?): Boolean {
        var slow = head
        var fast = head
        while (fast?.next != null) {
            slow = slow?.next
            fast = fast.next?.next
            if (slow == fast) {
                return true
            }
        }
        return false
    }
}