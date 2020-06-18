package jdbc.mvc;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.LinkedList;
import java.util.Queue;

public class Algorithm6_14 {
	
	private int tail;
	private Queue<Integer> queue;
	
	class MyStack{
		/** Initialize your data structure here. */
	    public MyStack() {
	    	queue = new LinkedList<Integer>();
	    }
	    
	    /** Push element x onto stack. */
	    public void push(int x) {
	    	tail = x;
	    	queue.add(x);
	    }
	    
	    /** Removes the element on top of the stack and returns that element. */
	    public int pop() {
	    	int size = queue.size();
	    	for(int i = 0;i < size - 2; i++) {
	    		queue.add(queue.remove());
	    	}
	    	tail = queue.remove();
	    	queue.add(tail);
	    	return queue.remove();
	    }
	    
	    /** Get the top element. */
	    public int top() {
	    	return tail;
	    }
	    
	    /** Returns whether the stack is empty. */
	    public boolean empty() {
	    	return queue.isEmpty();
	    }
	}
}

