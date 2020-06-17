class MyQueue {

    Stack<Integer> inStack;
    Stack<Integer> outStack;

    /** Initialize your data structure here. */
    public MyQueue() {
        inStack = new Stack<>(); // 入队用的栈
        outStack = new Stack<>(); // 出队用的栈，如果size为0，则把inStack所有元素出栈然后入栈到这里
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        inStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if(outStack.size() == 0) {
            if(inStack.size() == 0) {
                return -1;
            }
            while(inStack.size() > 0) {
                outStack.push(inStack.pop());
            }
        }
        return outStack.pop();
    }
    
    /** Get the front element. */
    public int peek() {
        if(outStack.size() == 0) {
            if(inStack.size() == 0) {
                return -1;
            }
            while(inStack.size() > 0) {
                outStack.push(inStack.pop());
            }
        }
        return outStack.peek();
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        if(inStack.size() == 0 && outStack.size() == 0) return true;
        return false;
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */