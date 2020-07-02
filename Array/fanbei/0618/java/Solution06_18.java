package com.example.computerdemo;

import java.util.LinkedList;
import java.util.Queue;

public class Solution06_18 {

    static class MaxQueue {
        Queue<Integer> queue;
        int maxValue;

        public MaxQueue() {
            queue = new LinkedList();
        }

        public int max_value() {
            if (queue.isEmpty()) return -1;
            return maxValue;
        }

        public void push_back(int value) {
            queue.offer(value);
            if (value > maxValue) maxValue = value;
        }

        public int pop_front() {
            if (queue.isEmpty()) return -1;
            int ans = queue.poll();
            if (ans == maxValue) {
                int size = queue.size();
                if (size == 0) {
                    maxValue = Integer.MIN_VALUE;
                    return ans;
                }
                maxValue = queue.peek();
                for (int i = 0; i < size; i++)
                    this.push_back(queue.poll());
            }
            return ans;
        }
    }
}
