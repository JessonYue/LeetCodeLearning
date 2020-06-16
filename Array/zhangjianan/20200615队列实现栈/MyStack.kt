class MyStack() {
    var q1=LinkedList<Int>()
     var q2=LinkedList<Int>()
     var top:Int=0
    /** Initialize your data structure here. */


    /** Push element x onto stack. */
    fun push(x: Int) {
		q1.add(x)
		top=x
    }

    /** Removes the element on top of the stack and returns that element. */
    fun pop(): Int {
        while(q1.size>1){
           top= q1.remove()
            q2.add(top)
        }
        val popData=q1.remove()
        val temp=q1;
        q1=q2
        q2=temp
        return popData
    }

    /** Get the top element. */
    fun top(): Int {
        return top
    }

    /** Returns whether the stack is empty. */
    fun empty(): Boolean {
        return q1.size<1
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