package L19

import Base.ListNode

/**
 *
 */
fun removeNthFromEnd(head: ListNode, n: Int): ListNode {
    var b = n
    val dummyHead = ListNode(-1)
    dummyHead.next = head
    var s = dummyHead
    var e = dummyHead

    while (n > 0) {
        s = s.next
        b --
    }
    while (s.next != null){
        s = s.next
        e = e.next
    }
    e.next = e.next.next
    return dummyHead.next
}