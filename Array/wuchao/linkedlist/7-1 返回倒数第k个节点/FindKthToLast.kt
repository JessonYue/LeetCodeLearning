package com.slow.lib.practice.linkedList

/**
 * @Author wuchao
 * @Date 2020/7/1-9:18 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class FindKthToLast {
    class ListNode(var `val`: Int) {
        var next: ListNode? = null
    }

    fun kthToLast(head: ListNode?, k: Int): Int {
        var slow = head
        var fast = ListNode(-1)
        fast.next = head
        var i = 0
        while(i<k){
            fast = fast.next!!
            i++
        }
        while(fast.next!=null){
            slow = slow?.next
            fast = fast.next!!
        }
        return slow?.`val`?:-1
    }
}