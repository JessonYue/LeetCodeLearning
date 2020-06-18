package jdbc.mvc;

import java.util.ArrayList;
import java.util.List;

import jdbc.mvp.Constrct;

public class Algorithm6_12 {

	public ListNode oddEvenList(ListNode head) {
		ListNode src = head;
		if (head == null) {
			return null;
		}else if (head != null&&head.next == null) {
			return head;
		}
		
		ListNode j = head;
		ListNode o = head.next;
		ListNode r = o;
		head = head.next.next;
		while (head != null) {
			j.next = head;
			j = head;
			
			if (head.next == null) {
				break;
			}else {
				o.next = head.next;
				o = head.next;
				head = head.next.next;
			}
		}
		
		o.next = null;
		j.next = r;
		return src;
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
