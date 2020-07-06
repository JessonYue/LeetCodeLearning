package day24


class ListNode(var `val`: Int) {
    var next: ListNode? = null
}



fun hasCycle(head: ListNode?): Boolean {
    var fast = head
    var slow = head

    while (fast != null){
        fast = fast.next
        if(fast != null){
            fast = fast.next
        }
        if(fast == slow){
            return true
        }
//        if(slow != null){
//            slow = slow.next
//        }
        slow = slow?.next
    }
    return false
}


fun main() {

}