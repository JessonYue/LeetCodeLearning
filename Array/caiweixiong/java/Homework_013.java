public class Homework_013 {

    // 化栈为队，LeetCode面试题03.04
    void homework_013_0304() {
        MyQueue obj = new MyQueue();
        obj.push(4);
        int param_2 = obj.pop();
        System.out.println(param_2);
        int param_3 = obj.peek();
        System.out.println(param_3);
        boolean param_4 = obj.empty();
        System.out.println(param_4);
    }

    class MyQueue {
        private Stack mQueue;

        /**
         * Initialize your data structure here.
         */
        public MyQueue() {
            mQueue = new Stack();
            mQueue.stack = null;
            mQueue.top = -1;
        }

        /**
         * Push element x to the back of queue.
         */
        public void push(int x) {
            Node node = new Node();
            node.data = x;
            node.next = null;
            if (mQueue.top == -1)
                mQueue.stack = node;
            else {
                Node temp = mQueue.stack;
                while (temp.next != null)
                    temp = temp.next;
                temp.next = node;
            }
            mQueue.top++;
        }

        /**
         * Removes the element from in front of queue and returns that element.
         */
        public int pop() {
            int ele = 0;
            if (mQueue.top == -1)
                return ele;
            Node top = mQueue.stack;
            ele = top.data;
            mQueue.stack = top.next;
            mQueue.top--;
            return ele;
        }

        /**
         * Get the front element.
         */
        public int peek() {
            int ele = 0;
            if (mQueue.top == -1)
                return ele;
            ele = mQueue.stack.data;
            return ele;
        }

        /**
         * Returns whether the queue is empty.
         */
        public boolean empty() {
            if (mQueue.top == -1)
                return true;
            return false;
        }
    }

    class Node {
        int data;
        Node next;
    }

    class Stack {
        Node stack;
        int top;
    }
}
