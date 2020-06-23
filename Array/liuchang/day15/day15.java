public class day15 {

    static class StackQueue {
        private final int MAXSIZE = 20;
        int[] queue = new int[20];
        int front = 0;
        int rear = 0;

        public void stackPush(StackQueue queue,int data) {
            queue.queue[rear] = data;
            rear++;
        }

        public void stackPop(StackQueue queue) {
            queue.queue[queue.rear] = queue.queue[queue.rear-1];
            queue.rear--;
        }

        public boolean isEmpty(StackQueue queue){
            return queue.front == queue.rear;
        }

        public boolean isFull(StackQueue queue){
            return queue.rear == MAXSIZE;
        }

        public void printStack(StackQueue queue){
            for (int i = 0; i < queue.rear ; i++) {

                System.out.println(queue.queue[i]);
            }
        }


    }

    public static void main(String[] args) {
        StackQueue stackQueue = new StackQueue();
        stackQueue.stackPush(stackQueue,1);
        stackQueue.stackPush(stackQueue,2);
        stackQueue.stackPush(stackQueue,3);
        stackQueue.stackPush(stackQueue,4);
        stackQueue.stackPush(stackQueue,5);
        stackQueue.stackPush(stackQueue,6);
        stackQueue.stackPush(stackQueue,7);
        stackQueue.stackPush(stackQueue,8);
        stackQueue.stackPush(stackQueue,9);
        stackQueue.stackPush(stackQueue,10);
//        stackQueue.printStack(stackQueue);
        stackQueue.stackPop(stackQueue);
        stackQueue.printStack(stackQueue);
    }
}
