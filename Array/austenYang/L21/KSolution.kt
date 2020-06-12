package L21

import DataStructure.ListNode

fun mergeTwoLists(l1: ListNode, l2: ListNode): ListNode? {
    var l11: ListNode? = l1
    var l22: ListNode? = l2
    val dummyHead = ListNode(-1)
    var pre = dummyHead.next
    while (l11 !== null && l22 !== null) {
        if (l11.`val` < l22.`val`) {
            pre.next = l11
            pre = l11
            l11 = l11.next
        } else {
            pre.next = l22
            pre = l22
            l22 = l22.next
        }
    }
    if (l11 === null) pre.next = l22 else pre.next = l11
    return dummyHead.next
}

fun main() {

}