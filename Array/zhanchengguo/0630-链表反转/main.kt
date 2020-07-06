package com.test.ktapplication

fun main() {
    val a = ListNode(1)
    val b = ListNode(2)
    val c = ListNode(3)
    val d = ListNode(4)
    val e = ListNode(5)
    a.next = b
    b.next = c
    c.next = d
    d.next = e
    e.next = null
    var result = reverseList1(a)
    while (result != null) {
        print("value is ${result.`val`}\n")
        result = result.next
    }

}

/**
 * 递归
 */
fun reverseList1(head: ListNode?): ListNode? {
    if (head == null || head.next == null) {
        return head
    }
    val lastNode = reverseList1(head.next)
    head?.next?.next = head
    head.next = null
    return lastNode
}

/**
 * 双指针
 */
fun reverseList2(head: ListNode?): ListNode? {
    var pre: ListNode? = null
    var current: ListNode? = head
    while (current != null) {
        var temp = current.next
        current.next = pre
        pre = current
        current = temp
    }
    return pre
}


data class ListNode(var `val`: Int) {
    var next: ListNode? = null
}