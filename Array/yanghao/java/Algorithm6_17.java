package jdbc.mvc;

import java.util.Stack;

import javax.sound.midi.Track;

public class Algorithm6_17 {

	class MyQueue{
		
		private Stack<Integer> stack;
		private Stack<Integer> stackTwo;
		int tail;
		
		/** Initialize your data structure here. */
	    public MyQueue() {
	    	stack = new Stack<>();
	    	stackTwo = new Stack<>();
	    }
	    
	    /** Push element x to the back of queue. */
	    public void push(int x) {
	    	stack.push(x);
	    }
	    
	    /** Removes the element from in front of queue and returns that element. */
	    public int pop() {
	    	stackTwo.clear();
	    	for(int i = 0; i < stack.size();i++) {
	    		if (i == 0) {
					tail = stack.get(i);
					continue;
				}else {
					stackTwo.push(stack.get(i));
				}
	    	}
	    	stack.clear();
	    	for (int i = 0; i < stackTwo.size(); i++) {
				stack.push(stackTwo.get(i));
			}
	    	return tail;
	    }
	    
	    /** Get the front element. */
	    public int peek() {
	    	return stack.get(0);
	    }
	    
	    /** Returns whether the queue is empty. */
	    public boolean empty() {
	    	return stack.isEmpty();
	    }
	}
}
