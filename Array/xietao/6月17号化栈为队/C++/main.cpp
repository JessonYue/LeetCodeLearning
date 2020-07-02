#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    return 0;
}

class MyQueue {
    stack<int> stackWrite,stackRead;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stackWrite.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val  = peek();
        stackRead.pop();
        return val;
    }

    /** Get the front element. */
    int peek() {
        if(stackRead.empty()){
            while(!stackWrite.empty()){
                int val = stackWrite.top();
                stackWrite.pop();
                stackRead.push(val);
            }
        }
        return stackRead.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stackWrite.empty() && stackRead.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
