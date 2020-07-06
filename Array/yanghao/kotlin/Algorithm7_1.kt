package staudy

class Algorithm7_1 {
	fun reverseList(head: ListNode?):ListNode?{
		var prev: ListNode? = null
		var curr : ListNode?= head
		while (curr != null){
			val nextTemp = curr.next
			curr.next = prev
			prev = curr
			curr = nextTemp
		}

		return prev
	}
}


class ListNode(var `val`: Int,var next: ListNode? = null)