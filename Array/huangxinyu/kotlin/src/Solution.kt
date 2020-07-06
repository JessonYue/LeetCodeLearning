import com.ryujin.algorithm.ListNode


class Solution {
    /**
     * 删除倒数第n个节点
     */
    fun removeNthFromEnd(listNode: ListNode?, n: Int): ListNode? {
        val preHead = ListNode(-1, listNode)
        var p1 = listNode
        var i = 0
        while (i < n) {
            assert(p1 != null)
            p1 = p1!!.next
            i++
        }
        var p2: ListNode? = preHead
        while (p1 != null) {
            p1 = p1.next
            p2 = p2!!.next
        }
        p2!!.next = p2.next!!.next
        return preHead.next
    }

    /**
     * 合并两个有序链表
     */
    fun mergeTwoLists(l1: ListNode?, l2: ListNode?): ListNode? {
        var l11 = l1;
        var l22 = l2;
        val preHead = ListNode(-1, l1)
        var pre = preHead
        while (l1 != null && l2 != null) {
            if (l11!!.value <= l22!!.value) {
                pre.next = l11
                l22 = l2.next
            } else {
                pre.next = l22
                l11 = l11.next
            }
            pre = pre.next!!
        }
        pre.next = l11 ?: l22;
        return preHead.next
    }

    fun oddEvenList(head: ListNode?): ListNode? {
        if (head == null) {
            return null
        }

        var l1 = head
        var l2 = head.next
        val l2Head = l2 //用于之后接到奇数链表末尾
        while (l2?.next != null) {
            l1?.next = l2.next
            l1 = l1?.next
            l2.next = l1?.next
            l2 = l2.next
        }
        l2?.next = l2Head;
        return head;
    }


    /**
     *判断单链表是否是回文链表
     * 使用快慢指针，快指针一次走两步，慢指针走一步，当快指针走到最后时，慢指针
     * 就走到中间位置（注意奇偶数），然后将慢指针作为链表头结点进行反转，再和原始链表
     * 从头结点开始比较，比较完后全部相同就是回文。时间复杂度是n+0.5n
     */
    fun isPalindrome(head: ListNode?): Boolean {
        var fast = head
        var slow = head
        while (fast?.next != null) {
            fast = fast.next!!.next
            slow = slow!!.next
        }
        if (fast != null) {
            //奇数个
            slow = slow!!.next
        }
        slow = reverse(slow)
        fast = head
        while (slow != null) {
            if (slow.value != fast!!.value) {
                return false
            }
            slow = slow.next
            fast = fast.next
        }
        return true
    }

    /**
     * 反转链表
     */
    private fun reverse(head: ListNode?): ListNode? {
        var head = head
        var pre: ListNode? = null
        while (head != null) {
            val next = head.next
            head.next = pre
            pre = head
            head = next
        }
        return pre
    }

    fun arrayNesting(nums: IntArray): Int {
        var ret = 0
        for (i in nums.indices) {
            var count = 0
            var next = i
            while (nums[next] != -1) {
                val temp = next
                next = nums[next]
                nums[temp] = -1
                count++
            }
            ret = ret.coerceAtLeast(count)
        }
        return ret
    }

    fun numOfSubarrays(arr: IntArray, k: Int, threshold: Int): Int {
        var ret = 0
        if (arr.size < k) {
            return ret
        }
        var i = 0
        val sumThreshld = k * threshold;
        var sum = 0
        while (i < k) {
            sum += arr[i]
            ++i
        }
        var delta = sum - sumThreshld
        while (i < arr.size) {
            delta += (arr[i] - arr[i - k])
            if (delta > 0) {
                ret++
            }
            i++
        }
        return ret
    }
}