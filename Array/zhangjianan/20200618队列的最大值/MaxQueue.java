package com.example.testapplication;

import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;

public class MaxQueue {
    Queue<Integer> queue=new LinkedList<Integer>();
    Deque<Integer> deque=new LinkedList<Integer>();

    public MaxQueue() {
    }

    public int max_value() {
        return deque.size()>0?deque.peek():-1;
    }

    public void push_back(int value) {
        queue.offer(value);
        while (deque.size() > 0 && deque.peekLast() < value) {
            deque.pollLast();
        }
        deque.offerLast(value);
    }

    public int pop_front() {
        int temp=queue.size()>0?queue.poll():-1;
        if (deque.size()>0&&temp==deque.peek()) {
            deque.poll();
        }
        return temp;
    }
}
