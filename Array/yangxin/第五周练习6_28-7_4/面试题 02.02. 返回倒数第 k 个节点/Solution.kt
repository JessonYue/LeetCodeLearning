class ListNode(val value: Int) {
        var next: ListNode? = null
    }

/**
 * 面试题 02.02. 返回倒数第 k 个节点
 * 实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。
 */
fun kthToLast(head: ListNode?, k: Int): Int {
	if (head == null || k<0) {
		return -1
	}

	var fast = head
	var low = head
	var tmp = k
	while(tmp != 0) {
		fast = fast?.next
		tmp--
	}

	while(fast != null) {
		fast = fast?.next
		low = low?.next
	}

	return low!!.value
}