#include <iostream>
#include "stack"
#include "string"

using namespace std;

/**
 * 思路：
 * 入队的话就先入栈 st1，
 * 出队的话先判断 st2 是否为空，如果为空就把 stack1 中的元素全部压入st2，
 * 因为 stack1 顶部的元素是后进入的，压入 st2 之后 st2 顶部的元素就是先进入的
 * 所以可以放心出队了，如果 st2 不为空，那么就出栈 st2 就好了。
 * 判定是否为空就直接看看 st1 和 st2 是不是都为空就好了
 */
class MyQueue {
private:
    stack<int> st1;
    stack<int> st2;
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
        int value = peek();
        st2.pop();
        return value;
    }

    /** Get the front element. */
    int peek() {
        if (st2.empty()) {
            while (!st1.empty()) {
                int value = st1.top();
                st1.pop();
                st2.push(value);
            }
        }
        return st2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

int main() {
    MyQueue *obj = new MyQueue();
    obj->push(4);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
    printf("params2 is %d,params3 is %d,params4 is %d\n", param_2, param_3, param_4);
    return 0;
}




