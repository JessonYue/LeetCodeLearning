package day18;

import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;

public class day18_leetcode_interview59 {

    //leetcode submit region begin(Prohibit modification and deletion)
    static class MaxQueue {
        Queue<Integer> queue = null;
        Deque<Integer> deque = null;
        public MaxQueue() {
            queue = new LinkedList<>();
            deque = new LinkedList<>();

        }

        public int max_value() {
            if(deque.isEmpty())
                return -1;
            return deque.peek();
        }

//        public void push_back(int value) {
//           queue.add(value);
//           if(!deque.isEmpty()){
//               int last = deque.getLast();   //3
//               while (last < value){    //3 <  5
//                   deque.removeLast();
//               }
//           }
//           deque.add(value);
//        }
public void push_back(int value) {
    queue.add(value);
    while (!deque.isEmpty() && deque.getLast()<value){    //3 < 5
        deque.removeLast();  //
    }
    deque.add(value);
}

        public int pop_front() {
            if(!queue.isEmpty()){
                Integer result = queue.poll();
                if(!deque.isEmpty() && result == deque.peek()){
                    deque.poll();
                }
                return result;
            }else{
                return -1;
            }

        }
    }

    /**
     * Your MaxQueue object will be instantiated and called as such:
     * MaxQueue obj = new MaxQueue();
     * int param_1 = obj.max_value();
     * obj.push_back(value);
     * int param_3 = obj.pop_front();
     */
//leetcode submit region end(Prohibit modification and deletion)
    public static void main(String[] args) {
        MaxQueue mq = new MaxQueue();

        mq.push_back(3);  //3
        mq.push_back(5);  // 3 5
        System.out.println(mq.max_value());  //5
        mq.push_back(4);  //3 5 4
        System.out.println(mq.max_value());  //5
        mq.pop_front();   //5 4
        mq.pop_front();   //4
        System.out.println(mq.max_value());  //4
        mq.push_back(3); //4 3
        System.out.println(mq.max_value());  //4
        mq.pop_front(); //3
        System.out.println(mq.max_value());  //3

    }
}
