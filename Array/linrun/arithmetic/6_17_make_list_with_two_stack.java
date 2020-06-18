package com.rlin.test;

import java.util.Stack;

/**
 *
 * 实现一个MyQueue类，该类用两个栈来实现一个队列。
 *
 * 示例：
 *
 * MyQueue queue = new MyQueue();
 *
 * queue.push(1);
 * queue.push(2);
 * queue.peek();  // 返回 1
 * queue.pop();   // 返回 1
 * queue.empty(); // 返回 false
 *
 * 说明：
 *
 * 你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size 和 is empty 操作是合法的。
 * 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
 * 假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。
 */
class MyQueue {

    private Stack<Integer> stack1;
    private Stack<Integer> stack2;
    private Integer firstElement;

    public MyQueue(){
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }

    public void push(int element){
        if(stack1.size() == 0){
            firstElement = element;
        }
        stack1.push(element);
    }

    public Integer peek(){
        return firstElement;
    }

    public Integer pop(){
        Integer topElement = null;
        while(stack1.size() > 1){
            stack2.push(stack1.pop());
        }
        if(stack1.size() == 1){
            topElement = stack1.pop();
        }
        while(stack2.size() != 0){
            stack1.push(stack2.pop());
        }
        return topElement;
    }

    public boolean empty(){
        return stack1.size() == 0;
    }

}
