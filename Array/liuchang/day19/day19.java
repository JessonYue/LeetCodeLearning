public class day19 {

    static class MyQueue{
        char data[] = new char[20];
        int front = 0;
        int rear = 0;

        public void pushQueue(MyQueue myQueue,String s){
            myQueue.data = s.toCharArray();
            myQueue.rear = data.length;
        }

        public void removeDuplicates(MyQueue myQueue){
            int num = -1;
            for (int k = 0; k < myQueue.rear-1; ++k) {
                if (myQueue.data[k] == myQueue.data[k + 1]) {
                    num = k;
                    break;
                }
            }
            if (num != -1) {
                char temp;
                int i, j;
                for (i = num; i < num + 2; ++i) {
                    temp = myQueue.data[num];
                    for (j = num; j < myQueue.rear-1; ++j) {
                        myQueue.data[j] = myQueue.data[j + 1];
                    }
                    myQueue.data[j] = temp;
                }
                myQueue.rear = myQueue.rear - 2;
                removeDuplicates(myQueue);
            }
        }
    }

    public static void main(String[] args) {
        MyQueue myQueue = new MyQueue();
        myQueue.pushQueue(myQueue,"abbaca");
        for (int i = 0; i < myQueue.rear ; i++) {
            System.out.println("====="+myQueue.data[i]);
        }
        myQueue.removeDuplicates(myQueue);
        for (int i = 0; i < myQueue.rear ; i++) {
            System.out.println("<===>"+myQueue.data[i]);
        }
    }

}
