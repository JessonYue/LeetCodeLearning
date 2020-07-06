package day31


  class ListNode(var `val`: Int) {
      var next: ListNode? = null
  }
class Solution {
    fun kthToLast(head: ListNode?, k: Int): Int {
        var fast = head
        var slow = head
        var kk = k
        while (kk!=0){
            kk -= 1;
            fast = fast?.next
        }

        while (fast!=null){
            fast = fast.next
            slow = slow?.next
        }

        return slow!!.`val`

    }
}