package com.ryujin.algorithm

import Solution


fun main() {
    val head = ListNode(
        1,
        ListNode(
            2,
            ListNode(
                3,
                ListNode(
                    4,
                    ListNode(5, null)
                )
            )
        )
    );
    val solution = Solution();
    val ret = solution.removeNthFromEnd(head, 2)
    println("1")
}