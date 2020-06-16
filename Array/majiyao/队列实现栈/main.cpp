#include <iostream>
#include <queue>

/**
 * 用队列实现栈
 * @return
 */
using namespace std;

class MyStack {
public:
    MyStack() = default;

    //入栈
    void push(int x){
        que.push(x);
        for (int i = 0; i < que.size(); ++i) {
            que.push(que.front());
            que.pop();
        }
    }

    //出栈
    int pop(){
        int val = top();
        que.pop();
        return val;
    }

    //获取栈顶值
    int top(){
        return que.front();
    }

    //判断栈是否为空
    bool empty(){
        return que.empty();
    }

private:
    queue<int> que;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}