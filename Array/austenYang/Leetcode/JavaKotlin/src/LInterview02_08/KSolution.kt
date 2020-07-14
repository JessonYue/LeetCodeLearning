package LInterview02_08

import Base.ListNode


fun detectCycle1(head: ListNode?): ListNode? {
    var varHead = head
    val container = HashSet<ListNode>()
    while (varHead != null) {
        if (container.contains(varHead)) {
            return varHead
        } else {
            container.add(varHead)
        }
        varHead = varHead.next
    }
    return null
}


fun detectCycle2(head: ListNode?): ListNode? {
//    if (head == null || head.next == null) {
//        return null
//    }
    if (head?.next == null) {
        return null
    }
    var slow = head
    var fast = head
    while (fast?.next != null) {
        slow = slow!!.next
        fast = fast.next.next
        if (fast === slow) {
            break
        }
    }
    if (fast?.next == null) {
        return null
    }

    fast = head
    while (fast !== slow) {
        fast = fast!!.next
        slow = slow!!.next
    }
    return fast
}

fun main() {

}