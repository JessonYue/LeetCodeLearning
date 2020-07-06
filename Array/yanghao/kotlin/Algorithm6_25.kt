package staudy

class Algorithm6_25 {

    fun detectCycle(head:ListNode?):ListNode?{
        if (head?.next == null){
            return null
        }

        var slow:ListNode? = head
        var fast:ListNode? = head
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

class ListNode(var `val`: Int, var next: ListNode?) {

}