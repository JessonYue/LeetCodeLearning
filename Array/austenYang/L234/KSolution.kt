package L234

import DataStructure.ListNode


/**
 *  将复制到数组中后用双指针法
 * 1.将链表复制到数组
 * 2.用前后两个指针，一个指向数组头，一指向数组尾
 * 3.比较指针指向的元素是否相等，直到两个指针相遇
 */
fun isPalindrome1(head: ListNode?): Boolean {
    var l = 0
    var cur = head
    while (cur != null) {
        l++
        cur = cur.next
    }


    cur = head
    val intArray = IntArray(l)
    var index = 0
    while (cur != null) {
        intArray[index++] = cur.`val`
        cur = cur.next
    }


    var p = 0
    var q = l - 1
    while (p < q) {
        if (intArray[p] != intArray[q]) {
            return false
        }
        p++
        q--
    }
    return true

}

 var first: ListNode? = null
fun isPalindrome2(head: ListNode?): Boolean {
    first = head
    return recursivelyCheck(head)
}
fun recursivelyCheck(head: ListNode?): Boolean {
    if (head != null) {
        if (!recursivelyCheck(head.next)) return false
        if (first!!.`val` != head.`val`) {
            return false
        }
        first = first!!.next
    }

    return true
}


fun main() {

}