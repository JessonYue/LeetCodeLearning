package com.slow.lib.practice.linkedList

/**
 * @Author wuchao
 * @Date 2020/7/29-9:13 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class MergeSortList {
    class ListNode(var `val`: Int) {
        var next: ListNode? = null
    }

    fun mergeTwoLists(l1: ListNode?, l2: ListNode?): ListNode? {
        val dummy = ListNode(-1)
        merge(dummy,l1,l2)
        return dummy.next
    }

    fun merge(root:ListNode?,left:ListNode?,right:ListNode?){
        if(left==null&&right==null) return
        if(left==null){
            root?.next = right
            merge(root?.next,left,right?.next)
            return
        }
        if(right==null){
            root?.next = left
            merge(root?.next,left.next,right)
            return
        }
        if(left.`val`<right.`val`){
            root?.next = left
            merge(root?.next,left.next,right)
        } else {
            root?.next = right
            merge(root?.next,left,right.next)
        }
        return
    }
}