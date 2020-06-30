package day25




class ListNode(var `val`: Int) {
    var next: ListNode? = null
}



fun hasCycle(head: ListNode?): ListNode? {
    var fast = head
    var slow = head

    while (fast!=null){
        fast = fast.next
        while (fast!=null && slow!=null)
        {
            fast = fast.next
            slow = slow.next
        }
        if(slow == fast){
            break
            //有环
        }
    }

    if (fast!=slow)
        return null
    fast = head
    while (fast != slow)
    {
        fast = fast?.next
        slow = slow?.next
    }

    return fast

}