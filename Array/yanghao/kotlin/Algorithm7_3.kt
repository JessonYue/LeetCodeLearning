package staudy

import kotlin.math.min

class Algorithm7_3 {

	fun findMiddleElement(head:ListNode?):ListNode?{
		var a = head
		var prevPtr:ListNode? = null
		var slowPtr:ListNode? = head
		var fastPtr:ListNode? = head

		while (fastPtr?.next != null){
			prevPtr = slowPtr
			slowPtr = slowPtr?.next
			fastPtr = fastPtr.next?.next
		}

		if (prevPtr != null){
			prevPtr.next = null
		}

		return slowPtr
	}

	fun sortedListToBST(head: ListNode?) : TreeNode?{
		var a: ListNode? = head ?: return null

		var mid = findMiddleElement(a)
		var node = TreeNode(mid!!.`val`)
		if (a == mid){
			return node
		}

		node.left = sortedListToBST(a)
		node.right = sortedListToBST(mid.next)
		return node
	}
}

class ListNode(var `val`: Int) {
	var next: ListNode? = null

}

class TreeNode(var `val`: Int) {
	var left: TreeNode? = null
	var right: TreeNode? = null

}