package day30


  class ListNode(var `val`: Int) {
      var next: ListNode? = null
  }
class Solution {
    fun reverseList(head: ListNode?): ListNode? {
        var pre:ListNode? = null
        var cur:ListNode? = head

        while (cur!=null){
            var tmp = cur.next
            cur.next = pre
            pre = cur
            cur = tmp
        }

        return pre

    }
}