package jdbc.mvc.interfaces;

import java.util.LinkedHashSet;
import java.util.Set;

public class Algorithm6_24 {

	public static boolean hashSolution(ListNode head) {
		Set<ListNode> set = new LinkedHashSet<>();
		while (head != null) {
			if (set.contains(head)) {
				return true;
			}
			set.add(head);
			head = head.next;
		}
		return false;
	}
}

class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
		next = null;
	}
}
