package com.test.ktapplication

class ListNode(var `val`: Int) {
    var next: ListNode? = null
}

fun main() {
    var a = ListNode(1)
    var b = ListNode(2)
    var c = ListNode(3)
    var d = ListNode(4)
    a.next = b
    b.next = c
    c.next = d
    d.next = c
    val result = hasCycle(a)
    print("result is ${result}")
}

fun hasCycle(head: ListNode?): Boolean {
    if (head?.next == null) {
        return false
    }
    var slow = head
    var fast = head.next
    while (slow != fast) {
        if (fast?.next == null) {
            return false
        }
        slow = slow?.next
        fast = fast?.next?.next
    }
    return true
}