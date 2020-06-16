package com;

class F {

	fun GetFuase(head1:ListNode?,head2:ListNode?) : ListNode? {
		if(head1 == null || head2 == null) return null
		
		var b:ListNode? = head1
		var a:ListNode? = head2
		while(a != null || b != null){
			a = if(a == null) head2 else a.next
			b = if(b == null) head1 else b.next
		}
		return a 
	}

	fun main(args: Array<String>) {

	}
}


class ListNode(var `val`: Int) {
	var next: ListNode? = null
}

