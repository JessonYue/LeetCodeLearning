public class day17 {

    static class MyStack{
        int top = -1;
        int data[] = new int[20];
    }

    static class MyQueue{
        MyStack frontStack;
        MyStack rearStack;

        public MyQueue() {
            this.frontStack = new MyStack();
            this.rearStack = new MyStack();
        }

        void pushQueque(int data){
            if (frontStack.top!=-1){
                for (int i = frontStack.top; i > -1; i--) {
                    rearStack.top++;
                    rearStack.data[rearStack.top] = frontStack.data[i];
                    frontStack.top--;
                }
            }
            rearStack.top++;
            rearStack.data[rearStack.top] = data;
        }

        void popQueue(){
            if (rearStack.top != -1) {
                for (int i = rearStack.top; i > -1; i--) {
                    frontStack.top++;
                    frontStack.data[frontStack.top] = rearStack.data[i];
                    rearStack.top--;
                }
            }

            frontStack.data[frontStack.top] =frontStack.data[frontStack.top - 1];
            frontStack.top--;
        }
    }

    public static void main(String[] args) {
        MyQueue queue = new MyQueue();
        queue.pushQueque(1);
        queue.pushQueque(2);
        queue.pushQueque(3);
        queue.pushQueque(4);
        queue.pushQueque(5);
        queue.pushQueque(6);
        queue.pushQueque(7);
        queue.pushQueque(8);
        queue.pushQueque(9);
        for (int i = 0; i <= queue.rearStack.top ; i++) {
            System.out.println("======="+queue.rearStack.data[i]);
        }
        queue.popQueue();
        for (int i = 0; i <= queue.frontStack.top ; i++) {
            System.out.println("<======="+queue.frontStack.data[i]);
        }
        queue.pushQueque(10);
        for (int i = 0; i <= queue.rearStack.top ; i++) {
            System.out.println("<=======>"+queue.rearStack.data[i]);
        }
    }
}
