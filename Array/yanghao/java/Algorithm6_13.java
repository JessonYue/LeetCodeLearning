package jdbc.mvc;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import jdbc.mvc.interfaces.Add;
import jdbc.mvc.interfaces.Delete;
import jdbc.mvc.interfaces.Find;
import jdbc.mvc.interfaces.Update;

public class Algorithm6_13 {

	public boolean isPalindrome(ListNode head) {
		ListNode slow = head;
		ListNode fast = head;
		ListNode prev = null;

		while (fast != null && fast.next != null) {
			ListNode oldCur = slow;
			slow = slow.next;
			fast = fast.next.next;
			oldCur.next = prev;
			prev = oldCur;
		}

		if (fast != null) {
			slow = slow.next;
		}

		while (slow != null) {
			if (slow.val != prev.val) {
				return false;
			}
			slow = slow.next;
			prev = prev.next;
		}

		return true;
	}

}

class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
	}
}
