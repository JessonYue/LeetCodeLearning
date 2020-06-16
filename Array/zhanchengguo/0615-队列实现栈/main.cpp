#include <iostream>
#include <queue>

using namespace std;

/**
 * 思路：队列实现栈，栈和队列的区别是栈是后进先出，而队列是先进先出，
 * 所以添加数据时，要把之前的数据全部移动到新添加的数据之后
 */
class MyStack {
private:
    queue<int> que;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
        for (int i = 0; i < que.size() - 1; i++) {
            int value = que.front();
            que.push(value);
            que.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int value = top();
        que.pop();
        return value;
    }

    /** Get the top element. */
    int top() {
        return que.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
};

int main() {
    MyStack *obj = new MyStack();
    obj->push(2);
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();
    return 0;
}



