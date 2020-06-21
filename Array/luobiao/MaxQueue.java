/**
请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1

示例 1：

输入: 
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出: [null,null,null,2,1,2]
示例 2：

输入: 
["MaxQueue","pop_front","max_value"]
[[],[],[]]
输出: [null,-1,-1]
 

限制：

1 <= push_back,pop_front,max_value的总操作数 <= 10000
1 <= value <= 10^5


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

解题思路：使用队列来实现，主要问题点在于取队列的最大值，去完成后需要手动复位，我们在取队列的最大值是采用遍历队列，取到队列的最大值，最后又将队列恢复

**/

class MaxQueue {
    private Queue<Integer> mQueue;
    private Queue<Integer> mOutQueue;
    private int mMaxValue = -1;
    public MaxQueue() {
        mQueue = new LinkedList<Integer>();
        mOutQueue = new LinkedList<Integer>();
    }

    public int max_value() {
        mMaxValue = -1;
        while (!mQueue.isEmpty()) {
            int currentValue = mQueue.poll();
            mMaxValue = currentValue > mMaxValue ? currentValue : mMaxValue;
            mOutQueue.offer(currentValue);
        }

        while (!mOutQueue.isEmpty()) {
            mQueue.offer(mOutQueue.poll());
        }

        return mMaxValue;
    }

    public void push_back(int value) {
        mQueue.offer(value);
    }

    public int pop_front() {
        return mQueue.isEmpty() ? -1 : mQueue.poll();
    }

}

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue obj = new MaxQueue();
 * int param_1 = obj.max_value();
 * obj.push_back(value);
 * int param_3 = obj.pop_front();
 */