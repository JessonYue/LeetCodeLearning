class MaxQueue {

    Queue<Integer> queue;
    Deque<Integer> deque; // 用于保存最大值，最大值永远在队头

    public MaxQueue() {
        queue = new LinkedList<>();
        deque = new LinkedList<>();
    }
    
    public int max_value() {
        if(deque.size() > 0) {
            return deque.getFirst();
        }
        return -1;
    }
    
    public void push_back(int value) {
        queue.add(value);
        if(deque.size() > 0) {
            while(deque.size() > 0 && deque.getLast() < value) {
                deque.pollLast();
            }
        }
        deque.addLast(value);
    }
    
    public int pop_front() {
        if(queue.size() > 0) {
            int value = queue.poll();
            if(deque.getFirst() == value) {
                deque.pollFirst();
            }
            return value;
        }
        return -1;
    }
}

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue obj = new MaxQueue();
 * int param_1 = obj.max_value();
 * obj.push_back(value);
 * int param_3 = obj.pop_front();
 */