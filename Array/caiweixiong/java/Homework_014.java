public class Homework_014 {

    // 队列的最大值，LeetCode面试题59-II
    void homework_014_59() {
        MaxQueue obj = new MaxQueue();
        int param_2 = obj.max_value();
        System.out.println(param_2);
        obj.push_back(4);
        int param_3 = obj.pop_front();
        System.out.println(param_3);
    }

    class MaxQueue {
        private final int MAX_ARRAY_SIZE = 10000;
        private int[] data;
        private int front;
        private int rear;
        private int maxValue;

        public MaxQueue() {
            data = new int[MAX_ARRAY_SIZE];
            front = rear = maxValue = -1;
        }

        public int max_value() {
            if (front == -1)
                return -1;
            int max = -1;
            int start = front;
            int end = (rear + 1) % MAX_ARRAY_SIZE;
            while (start != end) {
                if (data[start] > max)
                    max = data[start];
                start = (start + 1) % MAX_ARRAY_SIZE;
            }
            maxValue = max;
            return max;
        }

        public void push_back(int value) {
            int end = (rear + 1) % MAX_ARRAY_SIZE;
            if (front == end) // 队满
                return;
            if (front == rear && front == -1) {
                front++;
                rear++;
                data[front] = value;
            } else {
                data[end] = value;
                rear = end;
            }
        }

        public int pop_front() {
            if (front == -1)
                return -1;
            int ele = data[front++];
            if (front > rear)   // 队空
                front = rear = -1;
            return ele;
        }
    }
}
