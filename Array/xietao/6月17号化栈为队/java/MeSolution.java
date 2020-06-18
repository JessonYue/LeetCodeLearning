import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class MeSolution {

    class MyQueue {
        Stack<Integer> stackWrite;
        Stack<Integer> stackRead;

        /** Initialize your data structure here. */
        public MyQueue() {
            stackWrite = new Stack<Integer>();
            stackRead = new Stack<Integer>();
        }

        /** Push element x to the back of queue. */
        public void push(int x) {
            stackWrite.push(x);
        }

        /** Removes the element from in front of queue and returns that element. */
        public int pop() {//移除栈顶元素
            peek();
            return stackRead.pop();
        }

        /** Get the front element. */
        public int peek() {//移除栈顶元素但是不删除
            if(!stackRead.isEmpty()){
                return stackRead.peek();
            }
            while(!stackWrite.isEmpty()){
                stackRead.push(stackWrite.pop());
            }
            return stackRead.peek();
        }

        /** Returns whether the queue is empty. */
        public boolean empty() {
            return stackWrite.isEmpty() && stackRead.isEmpty();
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
}

