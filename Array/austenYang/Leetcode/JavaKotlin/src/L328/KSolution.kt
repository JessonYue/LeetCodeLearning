package L328

import DataStructure.ListNode


internal fun oddEvenListK1(head: ListNode?): ListNode? {
    if (head?.next == null) return head
    val oddHeadPre = ListNode(-1)
    var odd = head
    oddHeadPre.next = odd

    var even = head.next
    val evenHead = even

    var cur = even.next

    var index = 3
    while (cur != null) {
        if (index % 2 == 1) {
            odd!!.next = cur
            odd = cur
        } else {
            even.next = cur
            even = cur
        }
        index++
        cur = cur.next


    }
    even.next = null
    odd!!.next = evenHead

    return oddHeadPre.next


}

fun main() {

    val listNode1 = ListNode(1)
    val listNode2 = ListNode(2)
    val listNode3 = ListNode(3)
    val listNode4 = ListNode(4)
    val listNode5 = ListNode(5)

//    listNode1.next = listNode2
//    listNode2.next = listNode3
//    listNode3.next = listNode4
//    listNode4.next = listNode5
    oddEvenListK1(null)

}