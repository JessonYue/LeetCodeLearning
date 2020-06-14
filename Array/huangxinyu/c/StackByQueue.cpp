//
// Created by hasee on 2020/6/15.
//

#include "StackByQueue.h"

/**
 * 每次新元素先入队，然后把旧元素取出重新入队，时间复杂度O(n)，空间O(1)
 * 1. push 1    [1]
 * 2. push 2    [1,2],[2,1]
 * 3. push 3    [2,1,3],[3,2,1]
 */
void StackByQueue::push(int x) {
    queue.push(x);
    for (int i = 0; i < queue.size() - 1; ++i) {
        queue.push(queue.front());
        queue.pop();
    }
}

void StackByQueue::pop() {
    queue.pop();
}

int StackByQueue::top() {
    return queue.front();
}

bool StackByQueue::empty() {
    return queue.empty();
}
