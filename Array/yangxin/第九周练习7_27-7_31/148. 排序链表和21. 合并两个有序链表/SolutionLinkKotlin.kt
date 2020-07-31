class SolutionLinkKotlin {
	class ListNode(var `val`: Int) {
        var next: ListNode? = null
    }

/**
     * 148. 排序链表
     * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
     */
    fun sortList(head: ListNode?): ListNode? {
        if (head?.next == null) return head

        var size = 0
        var p = head
        while (p != null) {
            p = p.next
            size++
        }

        var step = 1
        p = ListNode(0)
        p.next = head
        var current: ListNode?
        var tail: ListNode?
        var left: ListNode?
        var right: ListNode?
        var two: Array<ListNode?>
        while (step < size) {
            current = p.next
            tail = p
            while (current != null) {
                left = current
                right = cut(left, step)
                current = cut(right, step)

                two = merge(left, right)
                tail!!.next = two[0]
                tail = two[1]
            }
            step *= 2
        }

        return p.next
    }

    private fun cut(head: ListNode?, n: Int): ListNode? {
        if (head == null) return null
        var tmp = head
        var length = n
        while (tmp != null && length > 1) {
            tmp = tmp.next
            length--
        }

        if (tmp == null) return null

        val r = tmp.next
        tmp.next = null
        return r
    }

    //按升序合并
    private fun merge(left: ListNode?, right: ListNode?): Array<ListNode?> {
        if (left == null && right == null) {
            return arrayOf(null, null)
        }

        var tmp: ListNode = ListNode(0)
        var tmpLeft = left
        var tmpRight = right
        val r = tmp
        while (tmpLeft != null && tmpRight != null) {
            if (tmpLeft.`val` < tmpRight.`val`) {
                tmp.next = tmpLeft
                tmpLeft = tmpLeft.next
            } else {
                tmp.next = tmpRight
                tmpRight = tmpRight.next
            }
            tmp = tmp.next!!
        }
        tmp.next = tmpLeft ?: tmpRight

        while (tmp.next != null) {
            tmp = tmp.next!!
        }
        return arrayOf(r.next, tmp)
    }

    /**
     * 21. 合并两个有序链表
     */
    fun mergeTwoLists(l1: ListNode?, l2: ListNode?): ListNode? {
        if (l1 == null) {
            return l2
        } else if (l2 == null) {
            return l1
        }

        return if (l1.`val` < l2.`val`) {
            l1.next = mergeTwoLists(l1.next, l2)
            l1
        } else {
            l2.next = mergeTwoLists(l1, l2.next)
            l2
        }
    }
	
}