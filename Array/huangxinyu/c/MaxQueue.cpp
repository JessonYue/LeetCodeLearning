//
// Created by hasee on 2020/6/19.
//
#include <queue>

class MaxQueue {
public:
    MaxQueue() {

    }

    int max_value() {
        if (queue.empty()) {
            return -1;
        }
        return deque.front();
    }

    void push_back(int value) {
        queue.push(value);
        while (deque.back() <= value) {
            deque.pop_back();
        }
        deque.push_back(value);
    }

    int pop_front() {
        if (queue.empty()) {
            return -1;
        }
        int i = queue.front();
        queue.pop();
        if (i == deque.front()) {
            deque.pop_front();
        }
        return i;
    }

private:
    std::queue<int> queue;
    std::deque<int> deque;
};