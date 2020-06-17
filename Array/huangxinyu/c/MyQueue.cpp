//
// Created by hasee on 2020/6/17.
//
#include <stack>

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top = peek();
        st2.pop();
        return top;
    }

    /** Get the front element. */
    int peek() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return st1.empty() && st2.empty();
    }

private:
    std::stack<int> st1, st2;
};