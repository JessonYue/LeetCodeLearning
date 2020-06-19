package com.slow.lib.practice.queue;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

/**
 * @Author wuchao
 * @Date 2020/6/18-2:29 PM
 * @description
 * @email 329187218@qq.com
 * @see
 */
class MaxQueue {
    private Queue<Integer> queue;
    private Queue<Integer> temp;
    private int max;
    public MaxQueue() {
        queue = new LinkedList<>();
        temp = new LinkedList<>();
        max = -1;
    }

    public int max_value() {
        return max;
    }

    public void push_back(int value) {
        queue.offer(value);
        if(value>max){
            max = value;
        }
    }

    public int pop_front() {
        if(queue.isEmpty()){
            return -1;
        }
        int pop = queue.poll();
        if(pop==max){
            max=-1;
            while(!queue.isEmpty()){
                int top = queue.poll();
                if(top>max){
                    max = top;
                }
                temp.offer(top);
            }
            while(!temp.isEmpty()){
                queue.offer(temp.poll());
            }
        }
        return pop;
    }
}
