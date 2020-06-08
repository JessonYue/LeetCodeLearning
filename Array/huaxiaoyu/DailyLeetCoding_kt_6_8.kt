package com.example.myapplication

import org.junit.Test

//Reverse a singly linked list.
//Example:
//Input: 1->2->3->4->5->NULL
//Output: 5->4->3->2->1->NULL
//Follow up:
//A linked list can be reversed either iteratively or recursively. Could you implement both?
class DayilyLeetCoding6_8 {

    class ListNode constructor(value: Int = 0, next: ListNode? = null) {
        var next: ListNode? = next;
        var value: Int = value
    }

    fun reverseList(head: ListNode?): ListNode? {
        var current = head
        var next = current?.next
        var pre: ListNode? = null
        while (next != null) {  // 4->3->2->1->NULL 5->null
            next = current?.next //记录next
            current?.next = pre //断开current重新指向pre
            pre = current //current变pre
            current = next //current++
        }
        return pre
    }

    @Test
    fun check() {
        val origin: ListNode = ListNode(
            1, ListNode(
                2, ListNode(
                    3, ListNode(4, ListNode(5))
                )
            )
        )

        var next: ListNode? = origin
        while (next != null) {
            println(next.value)
            next = next.next
        }
        println("---")

        var node: ListNode? = reverseList(origin)
        while (node != null) {
            println(node.value)
            node = node.next
        }

    }
}