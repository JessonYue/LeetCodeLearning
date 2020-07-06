package staudy

class Algorithm7_4 {
    fun detectCycle(head:ListNode?) : ListNode?{
        var a = head
        if (a?.next == null){
            return null
        }

        var slow =head
        var fast = head
        while (fast?.next != null){
            slow = slow?.next
            fast = fast.next?.next
            if (slow == fast){
                break
            }
        }

        if (fast?.next == null){
            return null
        }

        slow = head
        while (slow != fast){
            slow = slow?.next
            fast = fast?.next
        }

        return slow
    }
}

class ListNode(var `val`: Int,var next: ListNode?)