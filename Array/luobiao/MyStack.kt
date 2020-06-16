/**
使用队列实现栈的下列操作：

push(x) -- 元素 x 入栈
pop() -- 移除栈顶元素
top() -- 获取栈顶元素
empty() -- 返回栈是否为空
注意:

你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-stack-using-queues
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


解题思路：对于这个算法主要的考点就是考点就是，队列和栈的区别，队列先进先出，由两个指针操作，而栈是先进后出，针对这样的特性，我们主要的问题就是处理在出栈的过程时，将队列最后进入的先给
移出去，这里采用两个队列来处理，每次在出栈的时候，先将队列移动到最后一个位置上，将之前的队列赋值给我们定义的第二个队列，再将队列1的值返回，最后将队列2赋值给队列1
**/


class MyStack() {

    private var mQueue: Queue<Int>? = LinkedList()
    private var mOutQueue: Queue<Int>? = LinkedList()
    private var mTopValue: Int = 0

    /** Initialize your data structure here. */


    /** Push element x onto stack. */
    fun push(x: Int) {
        mQueue?.offer(x)
        mTopValue = x
    }

    /** Removes the element on top of the stack and returns that element. */
    fun pop(): Int {
        while (mQueue!!.size > 1) {
            mTopValue = mQueue!!.poll()
            mOutQueue?.add(mTopValue)
        }
        val temp = mQueue
        mQueue = mOutQueue
        mOutQueue = temp
        return mOutQueue!!.poll()
    }

    /** Get the top element. */
    fun top(): Int {
        return mTopValue
    }

    /** Returns whether the stack is empty. */
    fun empty(): Boolean {
        return mQueue!!.isEmpty()
    }

}

/**
 * Your MyStack object will be instantiated and called as such:
 * var obj = MyStack()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.empty()
 */