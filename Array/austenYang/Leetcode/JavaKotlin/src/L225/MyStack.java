package L225;

import java.util.LinkedList;
import java.util.Queue;

public class MyStack {
    private Queue<Integer> queue1;
    private Queue<Integer> queue2;
    private int top;

    public MyStack() {
        queue1 = new LinkedList<>();
        queue2 = new LinkedList<>();
    }

    /**
     * Push element x onto stack.
     */
    public void push(int x) {
        queue1.add(x);
        top = x;
    }

    /**
     * 队列模仿栈
     * 两个队列，
     * 执行队列中的 remove 是从头删 删到最后一个就是栈顶的元素
     * 在这个删除过程中，将其他放入到另一个元素，
     * 再和第一个交换
     * Removes the element on top of the stack and returns that element.
     */
    public int pop() {
        while (queue1.size() > 1) {
            top = queue1.remove();
            queue2.add(top);
        }
        Integer pop = queue1.remove();


        /**
         * 两个队列做交换
         */
        Queue<Integer> temp = queue1;
        queue1 = queue2;
        queue2 = temp;

        return pop;
    }

    /**
     * Get the top element.
     */
    public int top() {
        if (empty()) {
            throw new IllegalArgumentException("stack is Empty !");
        }
        return top;
    }

    /**
     * Returns whether the stack is empty.
     */
    public boolean empty() {
        return queue1.isEmpty();
    }

    public static void main(String[] args) {
        MyStack myStack = new MyStack();
        myStack.push(1);
        myStack.push(2);
        myStack.push(3);


        System.out.println(myStack.top());

        System.out.println(myStack.empty());
        int pop1 = myStack.pop();
        int pop2 = myStack.pop();
        int pop3 = myStack.pop();
        System.out.println(pop1);
        System.out.println(pop2);
        System.out.println(pop3);
        System.out.println(pop3);
        System.out.println(myStack.empty());
    }
}
