import java.util.LinkedList;
import java.util.Queue;

public class Solution_225 {
    private Queue<Integer> a;//输入
    private Queue<Integer> b;//输出
    /** Initialize your data structure here. */
    public Solution_225() {
        a = new LinkedList<>();
        b = new LinkedList<>();
    }

    /** Push element x onto stack. */
    public void push(int x) {
        a.offer(x);
        while(!b.isEmpty()) {
            a.offer(b.poll());
        }
        Queue<Integer> tmp = a;
        a = b;
        b = tmp;
    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return b.poll();
    }

    /** Get the top element. */
    public int top() {
        return   b.peek();
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        return b.isEmpty();
    }

    public int size() {
        return b.toArray().length;
    }

    public int e(int index) {
       return (int) b.toArray()[index];
    }

    public static void main(String[] args) {
        Solution_225 stack = new Solution_225();
        printStack(stack);
        stack.push(2);
        stack.push(3);
        stack.push(5);
        printStack(stack);
        stack.pop();
        printStack(stack);
    }

    private static void printStack(Solution_225 stack) {
        if (stack.empty()) return;
        StringBuilder stringBuilder = new StringBuilder();
        for(int i =0;i<stack.size();i++) {
            stringBuilder.append(stack.e(i) + ", ");
        }
        System.out.println(stringBuilder);
    }
}
