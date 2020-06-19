public class day16 {

    static class StackQueue {
        private final int MAXSIZE = 20;
        char[] queue = new char[MAXSIZE];
        int front = 0;
        int rear = 0;

        public void stackPush(StackQueue queue, char data) {
            queue.queue[rear] = data;
            rear++;
        }

        public void stackPop(StackQueue queue) {
            queue.queue[queue.rear] = queue.queue[queue.rear - 1];
            queue.rear--;
        }

        public boolean isEmpty(StackQueue queue) {
            return queue.front == queue.rear;
        }

        public boolean isFull(StackQueue queue) {
            return queue.rear == MAXSIZE;
        }

        public void printStack(StackQueue queue) {
            for (int i = 0; i < queue.rear; i++) {

                System.out.println(queue.queue[i]);
            }
        }

        public boolean isValid(StackQueue queue) {
            for (int i = 0; i < queue.rear; i = i + 2) {
                if (queue.queue[i] == '(') {
                    if (queue.queue[i + 1] != ')') {
                        return false;
                    }
                }
                if (queue.queue[i] == '{') {
                    if (queue.queue[i + 1] != '}') {
                        return false;
                    }
                }
                if (queue.queue[i] == '[') {
                    if (queue.queue[i + 1] != ']') {
                        return false;
                    }
                }
            }
            return true;
        }


    }

    public static void main(String[] args) {
        StackQueue stackQueue = new StackQueue();
        stackQueue.stackPush(stackQueue, '(');
        stackQueue.stackPush(stackQueue, ')');
        stackQueue.stackPush(stackQueue, '{');
        stackQueue.stackPush(stackQueue, '}');
        stackQueue.stackPush(stackQueue, '[');
        stackQueue.stackPush(stackQueue, ']');
        System.out.println(stackQueue.isValid(stackQueue));
    }

}
