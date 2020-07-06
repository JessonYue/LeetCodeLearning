import com.ryujin.algorithm.ListNode

class DetectCycle {
    fun detectCycle(head: ListNode): ListNode? {
        var slow = head;
        var fast = head;
        while (fast.next != null) {
            fast = fast.next!!.next!!
            slow = slow.next!!
            if (slow == fast) {
                break
            }

        }
        if (slow != fast) {
            return null
        }
        fast = head
        while (fast != slow) {
            fast = fast.next!!
            slow = slow.next!!
        }
        return fast
    }
}