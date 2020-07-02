package com.test.ktapplication

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
    e.next = null
    val result = sortedListToBST(a)
    print("value is ${result}\n")
}

fun sortedListToBST(head: ListNode): TreeNode? {
    return buildTree(head, null)
}


fun buildTree(head: ListNode?, tail: ListNode?): TreeNode? {
    if (head === tail) {
        return null
    }
    var fast = head
    var slow = head
    while (fast !== tail && fast?.next !== tail) {
        fast = fast?.next?.next
        slow = slow?.next
    }
    val root = TreeNode(slow?.`val`)
    root.left = buildTree(head, slow)
    root.right = buildTree(slow?.next, tail)
    return root
}


class ListNode(var `val`: Int) {
    var next: ListNode? = null
}

class TreeNode(var `val`: Int?) {
    var left: TreeNode? = null
    var right: TreeNode? = null
}