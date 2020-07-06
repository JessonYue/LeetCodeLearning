package staudy

class Algorithm6_26 {
     fun deleteNode(node:ListNode?){
         node!!.`val` = node.next!!.`val`
         node.next = node.next!!.next
     }
}

class ListNode(var `val`: Int, var next: ListNode?) {

}