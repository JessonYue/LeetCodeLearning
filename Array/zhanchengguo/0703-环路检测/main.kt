package com.example.kotlinproject

import java.lang.StringBuilder

fun main() {
    val a = ListNode(-10)
    val b = ListNode(-3)
    val c = ListNode(0)
    val d = ListNode(3)
    val e = ListNode(9)
    a.next = b
    b.next = c
    c.next = d
    d.next = e
    e.next = c
    var result = detectCycle(a)
    print("result is ${result?.`val`}")
}

fun detectCycle(head: ListNode?): ListNode? {
    if (head?.next == null) {
        return null
    }
    var fast = head
    var slow = head
    while (fast?.next != null) {
        fast = fast?.next?.next
        slow = slow?.next
        if (fast == slow) {
            break
        }
    }
    if (fast?.next == null) {
        return null
    }
    fast = head
    while (fast != slow) {
        fast = fast?.next
        slow = slow?.next
    }
    return fast
}


class ListNode(var `val`: Int) {
    var next: ListNode? = null
}