#include <iostream>
#include <queue>

using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;

    return 0;
}
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
        for(int i = 1; i < que.size(); i++){
            que.push(que.front());
            que.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val = top();
        que.pop();
        return val;
    }

    /** Get the top element. */
    int top() {
        return  que.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return  que.empty();
    }
private:
    queue<int> que;
};
