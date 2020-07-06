package com.slow.lib.practice.tree

/**
 * @Author wuchao
 * @Date 2020/6/29-2:24 PM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class SortedLinkedListToBST {
    class ListNode(var `val`: Int) {
        var next: ListNode? = null
    }

    class TreeNode(var `val`: Int) {
        var left: TreeNode? = null
        var right: TreeNode? = null
    }
    fun getMiddleNode(head:ListNode?,tail:ListNode?): ListNode? {
        var slow = head
        var fast = head
        while(fast!=tail&&fast?.next != tail){
            slow = slow?.next
            fast = fast?.next?.next
        }
        return slow
    }
    fun toBST(head:ListNode?,tail:ListNode?): TreeNode? {
        if(head==tail){
            return null
        }
        val middleNode = getMiddleNode(head,tail)
        val root = TreeNode(middleNode?.`val`?:0)
        root.left = toBST(head,middleNode)
        root.right = toBST(middleNode?.next,tail)
        return root
    }

    fun sortedListToBST(head: ListNode?): TreeNode? {
        return toBST(head,null)
    }
}