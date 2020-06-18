package com.lanfairy.ndkstudy;

import java.util.Iterator;
import java.util.LinkedList;

public class MaxQueue {
    private LinkedList<Integer> items;
    private int maxItem;

    public MaxQueue() {
        items = new LinkedList<>();
        maxItem = -1;
    }

    private boolean isEmpty(){
        return items.isEmpty();
    }

    public int max_value() {
        return maxItem;
    }

    public void push_back(int value) {
        items.offer(value);
        if (value>maxItem)
            maxItem = value;
    }

    public int pop_front() {
        if (items.isEmpty())return -1;
        int res = items.poll();
        if (items.isEmpty()){
            maxItem = -1;
            return res;
        }

        Iterator<Integer> iterator = items.iterator();
        maxItem = -1;
        while (iterator.hasNext()){
            Integer value = iterator.next();
            if (value>maxItem)
                maxItem = value;
        }

        return res;
    }


}
