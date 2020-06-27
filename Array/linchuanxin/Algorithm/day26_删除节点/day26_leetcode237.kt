package day26

import sun.rmi.runtime.Log
import java.util.ArrayList



 class ListNode(var `val`: Int) {
     var next: ListNode? = null
 }

class Solution {
    fun deleteNode(node: ListNode?) {
        node?.`val` = node?.next?.`val`!!
        node.next = node.next!!.next
    }
}

