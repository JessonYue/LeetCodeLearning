import java.util.Stack;

public class Solution_06_17 {


    private Stack<Integer> stack;

    private Stack<Integer> stackhelp;

    /** Initialize your data structure here. */
    public Solution_06_17() {
        stack = new Stack<Integer>();
        stackhelp = new Stack<Integer>();
    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        stack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        while (! stack.isEmpty()) {
            stackhelp.push(stack.pop());
        }
        int res = stackhelp.pop();
        while (! stackhelp.isEmpty()) {
            stack.push(stackhelp.pop());
        }
        return res;
    }

    /** Get the front element. */
    public int peek() {
        while (! stack.isEmpty()) {
            stackhelp.push(stack.pop());
        }
        int res = stackhelp.peek();
        while (! stackhelp.isEmpty()) {
            stack.push(stackhelp.pop());
        }
        return res;
    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        return stack.empty();
    }
}
