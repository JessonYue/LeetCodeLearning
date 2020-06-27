package com.slow.lib.practice.linkedList

/**
 * @Author wuchao
 * @Date 2020/6/25-5:32 PM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class FindLinkedListCycleEntryNode {
    class ListNode(var `val`: Int) {
        var next: ListNode? = null
    }

    fun detectCycle(head: ListNode?): ListNode? {
        var slow = head
        var fast = head
        while(fast?.next != null){
            slow = slow?.next
            fast = fast.next?.next
            if(slow==fast){
                break
            }
        }
        if(fast?.next == null){
            return null
        }
        fast = head
        while(slow!=fast){
            slow = slow?.next
            fast = fast?.next
        }
        return slow
    }
}