package com.jdbc.example;

import java.sql.SQLException;

public class Algorithm6_10 {
	
	public static ListNode AddListNode(ListNode headA,ListNode headB) {
		ListNode res = new ListNode(0),next = res;
		
		while(headA != null && headB != null) {
			if (headA.val > headB.val) {
				next.next = headB;
				next = next.next;
				headB = headB.next;
			}else {
				next.next = headA;
				next = next.next;
				headA = headA.next;
			}
		}
		
		if (headA != null) {
			next.next = headA;
		}
		
		if (headB != null) {
			next.next = headB;
		}
		
		return res.next;
	}
}

class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
	}
}
