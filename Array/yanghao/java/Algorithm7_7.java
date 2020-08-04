package com.example.servlet;

import java.io.IOException;
import java.util.Date;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Algorithm7_7 {
	
	public ListNode removeElements(ListNode head, int val) {
	    ListNode sentinel = new ListNode(0);
	    sentinel.next = head;

	    ListNode prev = sentinel, curr = head;
	    while (curr != null) {
	      if (curr.val == val) prev.next = curr.next;
	      else prev = curr;
	      curr = curr.next;
	    }
	    return sentinel.next;
	  }

}


  class ListNode {
      int val;
      ListNode next;
      ListNode(int x) { val = x; }
  }
 
