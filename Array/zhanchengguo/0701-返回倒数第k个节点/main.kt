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
    var result = kthToLast(a, 3)
    print("value is ${result}\n")
}

fun kthToLast(head: ListNode?, k: Int): Int? {
    var fast = head
    var slow = head
    var num = k
    while (num-- > 0) {
        fast = fast?.next
    }
    while (fast != null) {
        fast = fast?.next
        slow = slow?.next
    }
    return slow?.`val`
}


data class ListNode(var `val`: Int) {
    var next: ListNode? = null
}