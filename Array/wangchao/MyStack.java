package com.example.alg_lib;

import java.util.LinkedList;
import java.util.Queue;

public class MyStack {

    //用队列实现栈

    Queue<Integer> queue;

    public MyStack(){
        queue = new LinkedList();
    }

    //入栈
    public void push(int x){
        queue.add(x);
        for (int i = 1; i < queue.size(); i++) {
            queue.add(queue.remove());
        }
    }

    //返回栈顶并且删除栈顶
    public int top(){
       return queue.poll();
    }

    //返回栈顶元素
    public int peek(){
        return queue.peek();
    }

    //判空
    public boolean isEmpty(){
        return queue.size() == 0;
   }

}
