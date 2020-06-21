day18public class day18 {

    static class MaxQueue{
        int data[] = new int[20];
        int front = 0;
        int rear = 0;
        int maxsize = 0;

       public void maxQueuePush_back(MaxQueue obj, int data){
           if (data > obj.maxsize) {
               obj.maxsize = data;
           }
           obj.data[obj.rear] = data;
           obj.rear++;
       }

        public void maxQueuePop_front(MaxQueue obj){
            int num = obj.data[obj.front];
            obj.front = (obj.front) + 1;
            if (num >= obj.maxsize) {
                obj.maxsize = 0;
                for (int i = obj.front; i < obj.rear; ++i) {
                    if (obj.data[i]>obj.maxsize){
                        obj.maxsize = obj.data[i];
                    }
                }
            }
        }

        public int maxQueueMax_value(MaxQueue obj) {
           return obj.maxsize;
        }
    }

    public static void main(String[] args) {
        MaxQueue maxQueue = new MaxQueue();
        maxQueue.maxQueuePush_back(maxQueue,9);
        maxQueue.maxQueuePush_back(maxQueue,2);
        maxQueue.maxQueuePush_back(maxQueue,3);
        maxQueue.maxQueuePush_back(maxQueue,4);
        maxQueue.maxQueuePush_back(maxQueue,5);
        maxQueue.maxQueuePush_back(maxQueue,6);
        maxQueue.maxQueuePush_back(maxQueue,7);
        maxQueue.maxQueuePush_back(maxQueue,8);
        maxQueue.maxQueuePush_back(maxQueue,1);
        System.out.println("===="+maxQueue.maxQueueMax_value(maxQueue));

        maxQueue.maxQueuePop_front(maxQueue);
        System.out.println("<>"+maxQueue.maxQueueMax_value(maxQueue));
    }
}
