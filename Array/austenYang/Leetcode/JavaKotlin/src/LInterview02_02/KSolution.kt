package LInterview02_02

import DataStructure.ListNode

var K = 1
fun kthToLast(head: ListNode, k: Int): Int {
    if (head.next == null) return head.`val`
    val `val` = kthToLast(head.next, k)
    return if (K++ >= k) `val` else head.`val`
}

fun main() {
    println(kthToLast(ListNode(intArrayOf(1, 2, 3, 4, 5, 6, 7, 8)), 3))
}