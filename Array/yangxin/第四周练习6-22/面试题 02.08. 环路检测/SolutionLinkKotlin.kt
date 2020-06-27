package com.example.admin.myapplication.link

/**
 *create by yx
 *on 2020/6/24
 */
class SolutionLinkKotlin {
    class ListNode(val value: Int) {
        var next: ListNode? = null
    }

    /**
     * 141链表是否有环
     */
    fun hasCycle(head: ListNode?): Boolean {
        if (head?.next == null) {
            return false
        }

        var fast = head.next
        var low = head
        while (fast != low) {
            if (fast?.next == null) {
                return false
            }
            fast = fast?.next?.next
            low = low?.next
        }

        return true
    }

    /**
     * 面试题 02.08. 环路检测
     * 给定一个有环链表，实现一个算法返回环路的开头节点。
     * 有环链表的定义：在链表中某个节点的next元素指向在它前面出现过的节点，则表明该链表存在环路。
     */

    fun detectCycle(head: ListNode?): ListNode? {
        if (head?.next == null) return null

        var fast = head
        var low = head
        while (fast?.next != null) {
            fast = fast?.next?.next
            low = low?.next
            if (fast == low) break
        }
        if (fast?.next == null) return null
        fast = head
        while (fast != low) {
            fast = fast?.next
            low = low?.next
        }
        return fast
    }
}