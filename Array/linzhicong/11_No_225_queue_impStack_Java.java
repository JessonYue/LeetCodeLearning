class MyStack {

    MyLinkNode top;

    /** Initialize your data structure here. */
    public MyStack() {

    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        if(top == null) {
            top = new MyLinkNode(x);
        } else {
            MyLinkNode node = new MyLinkNode(x);
            node.next = top;
            top = node;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        if(top == null) return -1;
        int ret = top.val;
        top = top.next;
        return ret;
    }
    
    /** Get the top element. */
    public int top() {
        if(top == null) return -1;
        return top.val;
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        if(top == null) return true;
        return false;
    }
}

class MyLinkNode{
    public int val;
    public MyLinkNode next;
    public MyLinkNode(int val) {
        this.val = val;
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */