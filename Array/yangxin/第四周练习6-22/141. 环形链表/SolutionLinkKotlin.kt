package com.example.admin.myapplication.link

/**
 *create by yx
 *on 2020/6/24
 */
class SolutionLinkKotlin {
    class ListNode(val value: Int) {
        var next: ListNode? = null
    }

    fun hasCycle(head: ListNode?): Boolean {
        if (head?.next == null) {
            return false
        }

        var fast = head.next
        var low = head
        while (fast != low) {
            if (fast?.next==null) {
                return false
            }
            fast = fast?.next?.next
            low = low?.next
        }

        return true
    }
}