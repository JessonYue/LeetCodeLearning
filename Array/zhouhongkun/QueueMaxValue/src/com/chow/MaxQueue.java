package com.chow;

import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;

public class MaxQueue {
    //正常插入数据的队列
    private Queue<Integer> queue;
    //双端队列，用来在队头存放最大元素的队列
    private Deque<Integer> deque;

    public MaxQueue() {
        queue = new LinkedList<>();
        deque = new LinkedList<>();
    }

    public int max_value() {
        return deque.isEmpty() ? -1 : deque.peekFirst();
    }

    public void push_back(int value) {
        queue.offer(value);

        int count = 1;
        while (!deque.isEmpty() && deque.peekLast() < value){
            count += 1;
            deque.pollLast();
        }

        while (count > 0){
            deque.offerLast(value);
            count--;
        }
    }

    public int pop_front() {
        deque.pollFirst();
        return queue.isEmpty() ? -1 : queue.poll();
    }
}
