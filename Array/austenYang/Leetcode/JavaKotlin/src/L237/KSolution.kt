package L237

import DataStructure.ListNode

fun deleteNode(node: ListNode) {
    node.`val` = node.next.`val`
    node.next = node.next.next
}

fun main() {
    val arrays = intArrayOf(12, 3, 4, 5, 6)
    val listNode = ListNode(arrays)
    val nodeFromIndex = listNode.getNodeFromIndex(1)
    Solution.deleteNode(nodeFromIndex)
    println(listNode)
}