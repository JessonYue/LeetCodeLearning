package day17;


import java.util.Stack;

public class day17_leetcode232 {
    static class MyQueue {

        Stack<Integer> stack1 = null;
        Stack<Integer> stack2 = null;

        /** Initialize your data structure here. */
        public MyQueue() {
            stack1 = new Stack<>();
            stack2 = new Stack<>();
        }

        /** Push element x to the back of queue. */
        public void push(int x) {
            stack1.push(x);
        }

        /** Removes the element from in front of queue and returns that element. */
        public int pop() {
//            while (stack2.isEmpty()){
//                stack2.push(stack1.pop());
//            }
//            return stack2.pop();
            if(stack2.isEmpty()){
                while (!stack1.isEmpty()){
                    stack2.push(stack1.pop());
                }
            }
            return stack2.pop();

//            if (stack2.empty()) {
//                int size = stack1.size();
//                for (int i = 0; i < size; i++)
//                    stack2.push(stack1.pop());
//            }
//            return stack2.pop();
        }

        /** Get the front element. */
        public int peek() {
            if(stack2.isEmpty()){
                while (!stack1.isEmpty()){
                    stack2.push(stack1.pop());
                }
            }
            return stack2.peek();


//            while (stack2.isEmpty()){
//                stack2.push(stack1.pop());
//            }
//            return stack2.peek();

            /*if (stack2.empty()) {
                int size = stack1.size();
                for (int i = 0; i < size; i++)
                    stack2.push(stack1.pop());
            }
            return stack2.peek();*/
        }

        /** Returns whether the queue is empty. */
        public boolean empty() {
            if(stack1.isEmpty()&&stack2.isEmpty()){
                return true;
            }else{
                return false;
            }
        }
    }

    public static void main(String[] args) {
        MyQueue myQueue = new MyQueue();
        //[[],[1],[2],[],[3],[]]
        myQueue.push(0);
        myQueue.push(2);
        myQueue.push(3);
        myQueue.push(4);
        System.out.println(myQueue.peek());
        System.out.println(myQueue.empty());

        System.out.println(myQueue.pop());
        System.out.println(myQueue.pop());
        System.out.println(myQueue.pop());
        System.out.println(myQueue.pop());
        System.out.println(myQueue.empty());

    }
}
