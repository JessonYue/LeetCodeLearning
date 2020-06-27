package com.slow.lib.practice.linkedList

/**
 * @Author wuchao
 * @Date 2020/6/26-8:49 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class DeleteNode {
    class ListNode(var `val`: Int) {
        var next: ListNode? = null
    }

    fun deleteNode(node: ListNode?) {
        var next = node?.next
        node?.`val` = next?.`val` ?: 0
        node?.next = next?.next
        next?.next = null
        next = null
    }
}