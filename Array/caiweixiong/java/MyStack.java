class MyStack {

    private Queue mStack;

    /**
     * Initialize your data structure here.
     */
    public MyStack() {
        mStack = new Queue();
        mStack.front = null;
        mStack.rear = null;
    }

    /**
     * Push element x onto stack.
     */
    public void push(int x) {
        Node node = new Node();
        node.data = x;
        node.next = null;
        if (mStack.front == null && mStack.rear == null)
            mStack.front = mStack.rear = node;
        else {
            node.next = mStack.front;
            mStack.front = node;
        }
    }

    /**
     * Removes the element on top of the stack and returns that element.
     */
    public int pop() {
        int ele = 0;
        if (mStack.front == null)
            return ele;
        ele = mStack.front.data;
        if (mStack.front == mStack.rear)
            mStack.front = mStack.rear = null;
        else
            mStack.front = mStack.front.next;
        return ele;
    }

    /**
     * Get the top element.
     */
    public int top() {
        if (mStack.front == null)
            return 0;
        else
            return mStack.front.data;
    }

    /**
     * Returns whether the stack is empty.
     */
    public boolean empty() {
        return mStack.front == null;
    }

    class Node {
        int data;
        Node next;
    }

    class Queue {
        Node front;
        Node rear;
    }
}