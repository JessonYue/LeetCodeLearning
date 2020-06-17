package com.slow.lib.practice.stack;

import java.util.Stack;

/**
 * 两个栈实现队列，要么在push时借助两个栈将顺序调整过来，保证栈底的是队列尾部，栈顶是队列首部，pop时就可以直接弹出
 * 还有一种是push时正常压入栈中，pop时借助两个栈将栈底的元素弹出也就是队列首部
 * 第一种实现思路简便一些
 * @Author wuchao
 * @Date 2020/6/17-10:02 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
class MyQueue {
    Stack<Integer> stack;
    Stack<Integer> temp;

    /** Initialize your data structure here. */
    public MyQueue() {
        stack = new Stack<>();
        temp = new Stack<>();
    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        while(!stack.isEmpty()){
            temp.push(stack.pop());
        }
        stack.push(x);
        while(!temp.isEmpty()){
            stack.push(temp.pop());
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        return stack.pop();
    }

    /** Get the front element. */
    public int peek() {
        return stack.peek();
    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        return stack.isEmpty();
    }
}
