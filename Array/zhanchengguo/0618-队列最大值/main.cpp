#include <iostream>
#include <queue>
#include <list>

using namespace std;

/**
 * 思路：通过一个双端队列存储最大值，第二大，。。。。
 */
class MaxQueue {
private:
    queue<int> que;
    list<int> maxQue;
public:
    MaxQueue() {
    }

    int max_value() {
        if (maxQue.empty()) {
            return -1;
        }
        return maxQue.front();
    }

    void push_back(int value) {
        que.push(value);
        while (!maxQue.empty() && value > maxQue.back()) {
            maxQue.pop_back();
        }
        maxQue.push_back(value);
    }

    int pop_front() {
        if (que.empty()) {
            return -1;
        }
        int front = que.front();
        que.pop();
        if (!maxQue.empty() && front == maxQue.front()) {
            maxQue.pop_front();
        }
        return front;
    }
};

int main() {
    MaxQueue *obj = new MaxQueue();
    int param_1 = obj->max_value();
    obj->push_back(5);
    int param_3 = obj->pop_front();
    return 0;
}

