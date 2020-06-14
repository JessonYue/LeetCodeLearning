//
// Created by hasee on 2020/6/15.
//

#ifndef C_STACKBYQUEUE_H
#define C_STACKBYQUEUE_H

#include <queue>

using namespace std;

class StackByQueue {
public:
    StackByQueue() = default;

    ~StackByQueue() = default;

    void push(int x);

    void pop();

    int top();

    int empty();

private:
    queue<int> queue;
};


#endif //C_STACKBYQUEUE_H
