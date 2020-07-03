package day33

class ListNode(var `val`: Int) {
    var next: ListNode? = null
}


fun detectCycle(head: ListNode?):ListNode?{
    var fast:ListNode? = head
    var slow:ListNode? = head

    while (fast != null){
        fast = fast.next
        if (fast!=null){
            fast = fast.next
            slow = slow?.next
        }

        if (fast == slow)
            break;
    }

    if (fast != slow)
        return null
    fast = head;
    while (fast!=slow){
        fast = fast?.next
        slow = slow?.next
    }

    return slow

}