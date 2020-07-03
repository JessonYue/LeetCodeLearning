package day15;


import java.util.LinkedList;
import java.util.Queue;

//用队列实现栈
public class day15 {
    private Queue<Integer> queue1;
    private Queue<Integer> queue2;

    /** Initialize your data structure here. */
    public day15() {
        queue1 = new LinkedList<>();
        queue2 = new LinkedList<>();
    }

    /** Push element x onto stack. */
    public void push(int x) {
        if(queue1.peek()!=null){
            while (queue1.peek()!=null){
                queue2.offer(queue1.poll());
            }
            queue1.offer(x);
            while (queue2.peek()!=null){
                queue1.offer(queue2.poll());
            }
        }else{
            queue1.offer(x);
        }

    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        if(queue1.peek()!=null){
            return queue1.poll();
        }else{
            return 0;
        }
    }

    /** Get the top element. */
    public int top() {
        if(queue1.peek()!=null){
            return queue1.peek();
        }else{
            return 0;
        }
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        if(queue1.peek()!=null){
            return false;
        }else{
            return true;
        }
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
//leetcode submit region end(Prohibit modification and deletion)
