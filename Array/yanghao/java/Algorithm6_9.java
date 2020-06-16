package com.jdbc.example;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Algorithm6_9 {
	public ListNode reverseList(ListNode head) {
		
		ListNode last = null;
		while(head != null) {
			ListNode next = head.next;
			head.next = last;
			last = head;
			head = next;
		}
		
		return last;
	}
	
	public static void main(String[] args) {
		
	}
}

class ListNode {
	int val;
	ListNode next;

	ListNode() {
	}

	ListNode(int val) {
		this.val = val;
	}

	ListNode(int val, ListNode next) {
		this.val = val;
		this.next = next;
	}
}
