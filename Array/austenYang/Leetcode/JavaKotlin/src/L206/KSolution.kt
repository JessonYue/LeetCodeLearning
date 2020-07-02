package L206

import DataStructure.ListNode

fun reverseList1(head: ListNode?): ListNode? {
    var pre: ListNode? = null
    var cur = head
    while (cur != null) {
        val curNext = cur.next
        cur.next = pre
        pre = cur
        cur = curNext
    }
    return pre
}

fun reverseList2(head: ListNode?): ListNode? {
    if (head?.next === null) {
        return head
    }
    val p = reverseList2(head.next)
    head.next.next = head;
    head.next = null
    return p
}

fun main() {
    val arrays = intArrayOf(1, 2, 3, 4, 5, 6, 7, 8, 9)
    val listNode1 = ListNode(arrays)
    val listNode2 = ListNode(arrays)
    println(listNode1)
    println(reverseList1(listNode1))
    println(reverseList2(listNode2))
}