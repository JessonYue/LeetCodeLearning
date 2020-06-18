import java.util.LinkedList;
import java.util.Queue;

public class MeSolution {

    static class MyStack {
        private int tail;
        private Queue<Integer> q;

        /** Initialize your data structure here. */
        public MyStack() {
            q = new LinkedList<Integer>();
        }

        /** Push element x onto stack. */
        public void push(int x) {
            tail = x;
            q.add(x);
        }

        /** Removes the element on top of the stack and returns that element. */
        public int pop() {
            int size = q.size();
            for(int i = 0; i< size -2; i++){
                q.add(q.remove());
            }
            tail = q.remove();
            q.add(tail);
            return q.remove();

        }

        /** Get the top element. */
        public int top() {
            return tail;
        }

        /** Returns whether the stack is empty. */
        public boolean empty() {
            return q.isEmpty();
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

}

