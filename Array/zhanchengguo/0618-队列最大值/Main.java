package com.example.kotlinproject;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Main {

    void main() {
        MaxQueue obj = new MaxQueue();
        int param_1 = obj.max_value();
        obj.push_back(5);
        int param_3 = obj.pop_front();
    }
}

class MaxQueue {

    private Queue<Integer> mQue;
    private List<Integer> mList;

    public MaxQueue() {
        mQue = new LinkedList<>();
        mList = new ArrayList<>();
    }

    public int max_value() {
        if (mList.isEmpty()) {
            return -1;
        }
        return mList.get(0);
    }

    public void push_back(int value) {
        mQue.add(value);
        while (!mList.isEmpty() && value > mList.get(mList.size() - 1)) {
            mList.remove(mList.size() - 1);
        }
        mList.add(value);
    }

    public int pop_front() {
        if (mQue.isEmpty()) {
            return -1;
        }
        int front = mQue.peek();
        mQue.poll();
        if (!mList.isEmpty() && mList.get(0) == front) {
            mList.remove(0);
        }
        return front;
    }
}
