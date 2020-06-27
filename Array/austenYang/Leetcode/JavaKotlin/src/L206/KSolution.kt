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

fun main() {
    val arrays = intArrayOf(1, 2, 3, 4, 5, 6, 7, 8, 9)
    val listNode = ListNode(arrays)
    println(listNode)
    println(Solution.reverseList1(listNode))
}