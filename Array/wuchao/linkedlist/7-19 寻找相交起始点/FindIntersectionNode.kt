package com.slow.lib.practice.linkedList

/**
 * @Author wuchao
 * @Date 2020/7/19-10:52 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class FindIntersectionNode {
    class ListNode(var `val`: Int) {
        var next: ListNode? = null
    }

    fun getIntersectionNode(headA: ListNode?, headB: ListNode?): ListNode? {
        if(headA==null&&headB==null) return null
        var currentA = headA
        var currentB = headB
        while(currentA!=currentB){
            currentA = currentA?.next
            currentB = currentB?.next
            if(currentA==null&&currentB==null) return null
            if(currentA==null){
                currentA = headB
            }
            if(currentB==null){
                currentB = headA
            }
        }
        return currentA
    }
}