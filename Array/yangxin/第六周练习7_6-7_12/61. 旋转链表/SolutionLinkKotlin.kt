package com.example.admin.myapplication.link

/**
 *create by yx
 *on 2020/6/24
 */
class SolutionLinkKotlin {

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

    fun reverseList(head: ListNode?): ListNode? {
        if (head == null) {
            return null
        }
        var newHead: ListNode? = null
        var next = head
        var tmp: ListNode? = null
        while (next != null) {
            tmp = next.next
            next.next = newHead
            newHead = next
            next = tmp
        }
        return newHead
    }

    /**
     * 面试题 02.02. 返回倒数第 k 个节点
     * 实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。
     */
    fun kthToLast(head: ListNode?, k: Int): Int {
        if (head == null || k < 0) {
            return -1
        }

        var fast = head
        var low = head
        var tmp = k
        while (tmp != 0) {
            fast = fast?.next
            tmp--
        }

        while (fast != null) {
            fast = fast?.next
            low = low?.next
        }

        return low!!.`val`
    }

    /**
     * 109. 有序链表转换二叉搜索树
     * 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
     * <p>
     * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
     * 此方法跟链表递归方法可能不一样，因为构建的树存在多种可能
     */
    class TreeNode(var `val`: Int) {
        var left: TreeNode? = null
        var right: TreeNode? = null
    }

    class ListNode(var `val`: Int) {
        var next: ListNode? = null
    }

    fun sortedListToBST(head: ListNode?): TreeNode? {
        if (head == null) {
            return null
        }

        val array = list2Array(head);

        return convertListToBST(array, 0, array.size - 1)
    }

    fun convertListToBST(array: ArrayList<Int>, left: Int, right: Int): TreeNode? {
        if (left > right) {
            return null
        }

        val mid = (left + right) / 2

        val root = TreeNode(array[mid])
        if (left == right) {
            return root
        }

        root.left = convertListToBST(array, left, mid - 1)
        root.right = convertListToBST(array, mid + 1, right)


        return root
    }

    fun list2Array(head: ListNode?): ArrayList<Int> {
        var next = head
        val array = arrayListOf<Int>()
        while (next != null) {
            array.add(next.`val`)
            next = next.next
        }
        return array
    }

    /**
     * 61. 旋转链表
     * 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
     */
    fun rotateRight(head: ListNode?, k: Int): ListNode? {
        if (head?.next == null || k == 0) {
            return head
        }

        var size = 1
        var tail = head
        while (tail?.next != null) {
            tail =tail.next
            size++
        }

        if (size == k) {
            return head
        }

        tail?.next = head
        var tailIndex = size - (k % size) - 1
        tail = head
        while (tailIndex > 0) {
            tail = tail?.next
            tailIndex--
        }

        val newHead = tail?.next!!
        tail?.next = null

        return newHead
    }
}