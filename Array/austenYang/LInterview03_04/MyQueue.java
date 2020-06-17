package LInterview03_04;

import java.util.Stack;

/**
 * https://leetcode-cn.com/problems/implement-queue-using-stacks-lcci/
 */
public class MyQueue {
    private Stack<Integer> stack1;
    private Stack<Integer> stack2;

    public MyQueue() {
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }

    public void push(int x) {
        stack1.push(x);
    }

    public int pop() {
        while (stack1.size() > 1) {
            stack2.push(stack1.pop());
        }
        int pop = stack1.pop();
        while (!stack2.isEmpty()) {
            stack1.push(stack2.pop());
        }
        return pop;
    }

    public int peek() {
        while (stack1.size() > 1) {
            stack2.push(stack1.pop());
        }
        int pop = stack1.pop();
        stack1.push(pop);
        while (!stack2.isEmpty()) {
            stack1.push(stack2.pop());
        }
        return pop;
    }

    public boolean empty() {
        return stack1.isEmpty();
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