package SwordOffer59;

import LInterview03_04.MyQueue;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

public class MaxQueue {
    private Queue<Integer> queue = new LinkedList<>();
    private int max = 1;
    public MaxQueue() {

    }

    public int max_value() {
        if(queue.isEmpty()){
            return -1;
        }
        return max;
    }

    public void push_back(int value) {
        if(value > max){
            max = value;
        }
        queue.add(value);
    }

    public int pop_front() {
        if(queue.isEmpty()){
            return -1;
        }
        return queue.poll();
    }

    public static void main(String[] args) {
        MaxQueue myQueue = new MaxQueue();
        int max = myQueue.max_value();
        System.out.println(max);
        myQueue.push_back(1);
        System.out.println(myQueue.max_value());
        System.out.println(myQueue.pop_front());

        System.out.println(myQueue.max_value());
        HashMap<String, String> stringStringHashMap = new HashMap<>();
        stringStringHashMap.put("austenyang","100");
    }
}
