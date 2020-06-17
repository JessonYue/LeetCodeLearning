/**
实现一个MyQueue类，该类用两个栈来实现一个队列。


示例：

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);
queue.peek();  // 返回 1
queue.pop();   // 返回 1
queue.empty(); // 返回 false

说明：

你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-queue-using-stacks-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

解题思路：使用栈来实现队列，主要是解决栈和队列的弹出方式不一致，针对栈是先进后出，队列先进先出，这里我们利用两个栈来实现队列的弹出方式，即就是先将栈1弹出在栈2中，然后返回栈2的数据，就是
队列的第一个数据

**/


class MyQueue {

    private Stack<Integer> mStack;
    private Stack<Integer> mTempStack;
    /** Initialize your data structure here. */
    public MyQueue() {
        mStack = new Stack<>();
        mTempStack = new Stack<>();
    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        mStack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        mTempStack.clear();
        while (!mStack.empty()) {
            mTempStack.push(mStack.pop());
        }

        int tempValue = mTempStack.pop();

        while (!mTempStack.empty()) {
            mStack.push(mTempStack.pop());
        }
        return tempValue;
    }

    /** Get the front element. */
    public int peek() {
        mTempStack.clear();
        while (!mStack.empty()) {
            mTempStack.push(mStack.pop());
        }

        int tempValue = mTempStack.peek();

        while (!mTempStack.empty()) {
            mStack.push(mTempStack.pop());
        }
        return tempValue;
    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        return mStack.empty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */