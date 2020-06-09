package com.jdbc.example;

public class E implements D{

	public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) return null;
		
		ListNode a = headA, b = headB;
		while (a != b) {
			a = a == null?headB:a.next;
			b = b == null?headA:b.next;
		}
		
		return a;
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