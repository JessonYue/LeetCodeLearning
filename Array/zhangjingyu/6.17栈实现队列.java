 class MyQueue {

        private Stack<Integer> numStack;
        private Stack<Integer> helpStack;

        /** Initialize your data structure here. */
        public MyQueue() {
            numStack = new Stack<>();
            helpStack = new Stack<>();
        }

        /** Push element x to the back of queue. */
        public void push(int x) {
            numStack.push(x);
        }

        /** Removes the element from in front of queue and returns that element. */
        public int pop() {
            peek();
            return helpStack.pop();
        }

        /** Get the front element. */
        public int peek() {
            if (helpStack.isEmpty()) {
                while (!numStack.isEmpty()) {
                    helpStack.push(numStack.pop());
                }
            }

            return helpStack.peek();
        }

        /** Returns whether the queue is empty. */
        public boolean empty() {
            return helpStack.isEmpty() && numStack.isEmpty();
        }
    }
