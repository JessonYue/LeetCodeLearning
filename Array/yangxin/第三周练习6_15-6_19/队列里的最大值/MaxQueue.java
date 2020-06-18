package com.example.admin.myapplication.stack;

import java.util.LinkedList;
import java.util.Queue;

/**
 * create by yx
 * on 2020/6/18
 * 面试题59 - II. 队列的最大值
 * 请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
 * <p>
 * 若队列为空，pop_front 和 max_value 需要返回 -1
 * <p>
 * 这个题里如果用栈来保存最大值，就必须考虑队列弹出时，栈也要把相应的值弹出，栈的弹出方式跟队列不同，所以会比较麻烦。
 * 好的办法是用队列来保存最大值，然后用同样的弹出方式来弹出数据
 */
public class MaxQueue {
    //使用队里接口，使方法标准
    private LinkedList<Integer> max_queue;
    //java里的链表同时具备栈和队的性质，使用时要注意用对对应的方法
    private Queue<Integer> queue;

    public MaxQueue() {
        max_queue = new LinkedList<>();
        queue = new LinkedList<>();
    }

    //队列先进先出，所以队头的值应该最大
    public int max_value() {
        if (queue.isEmpty()) {
            return -1;
        } else {
            return max_queue.peek();
        }
    }

    public void push_back(int value) {
        queue.add(value);
        //因为是队列，保证前面的值比后面的值大，所以需要清除小的值,这里应该不能使用等于防止多个重复值情况
        while (max_queue.size() > 0 && max_queue.getLast() < value) {
            max_queue.removeLast();
        }
        max_queue.add(value);
    }

    public int pop_front() {
        if (queue.isEmpty()) {
            return -1;
        } else {
            int result = queue.poll();
            if (max_queue.size() > 0 && result == max_queue.peek()) {
                max_queue.poll();
            }
            return result;
        }
    }
}
