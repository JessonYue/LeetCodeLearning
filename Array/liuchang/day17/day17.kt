package net.study.kotlintest

/**
 * @author       刘畅
 * @createdate   2020/6/20
 * @describe
 */
class day17{
    class MyStack {
        var top = -1;
        var data = IntArray(20, { it * it });
    }

    class MyQueue {
        var frontStack:MyStack = MyStack();
        var rearStack:MyStack = MyStack();

        fun pushQueue(data:Int){
            if (frontStack.top!=-1){
                for (i in frontStack.top downTo 0 ){
                    rearStack.top++;
                    rearStack.data[rearStack.top] = frontStack.data[i];
                    frontStack.top--;


                }



            }
            rearStack.top++;
            rearStack.data[rearStack.top] = data;
        }

        fun popQueue(){
            if (rearStack.top != -1) {
                for (i in rearStack.top downTo 0) {
                    frontStack.top++;
                    frontStack.data[frontStack.top] = rearStack.data[i];
                    rearStack.top--;
                }
            }

            frontStack.data[frontStack.top] =frontStack.data[frontStack.top - 1];
            frontStack.top--;

        }
    }

    fun main(arg: Array<String>) {
        var queue: MyQueue = MyQueue();
        queue.pushQueue(1);
        queue.pushQueue(2);
        queue.pushQueue(3);
        queue.pushQueue(4);
        queue.pushQueue(5);
        queue.pushQueue(6);
        queue.pushQueue(7);
        queue.pushQueue(8);
        queue.pushQueue(9);
        for (i in 0 until queue.rearStack.top+1){
            System.out.println("====="+queue.rearStack.data[i]);
        }
        queue.popQueue();
        for (i in 0 until queue.frontStack.top+1){
            System.out.println("<====="+queue.frontStack.data[i]);
        }
        queue.pushQueue(10);
        for (i in 0 until queue.rearStack.top+1){
            System.out.println("====="+queue.rearStack.data[i]);
        }
    }
}