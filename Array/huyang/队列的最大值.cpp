class MaxQueue {
private:
    queue<int> que;
    list<int> maxQueue;
public:
    MaxQueue() {
        
    }
    
    int max_value() {
        if(maxQueue.empty())
        {
            return -1;
        }
        return maxQueue.front();
    }
    
    void push_back(int value) {
        que.push(value);
        while (!maxQueue.empty() && value > maxQueue.back())
        {
            maxQueue.pop_back();
        }
        maxQueue.push_back(value);
    }
    
    int pop_front() {
        if(que.empty())
        {
            return -1;
        }
        int front = que.front();
        que.pop();
        if (!maxQueue.empty() && maxQueue.front() == front)
        {
            maxQueue.pop_front();
        }
        return front;
    }
};
/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */