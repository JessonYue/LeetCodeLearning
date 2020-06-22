package net.study.kotlintest

/**
 * @author       刘畅
 * @createdate   2020/6/19
 * @describe
 */
class day15 {

    class StackQueue {
        var queue = IntArray(20, { it * it });
        var front = 0;
        var rear = 0;

        fun stackPush(queue: StackQueue, data: Int) {
            queue.queue[queue.rear] = data;
            queue.rear ++;
        }

        fun stackPop(queue:StackQueue){
            queue.queue[queue.rear] = queue.queue[queue.rear-1];
            queue.rear--;

        }

        fun printStack(queue:StackQueue){
            for (i in 0 until queue.rear){
                System.out.println(queue.queue[i]);
            }
        }


    }

    fun main(arg: Array<String>) {
        var stack :StackQueue = StackQueue();
        stack.stackPush(stack,1);
        stack.stackPush(stack,2);
        stack.stackPush(stack,3);
        stack.stackPush(stack,4);
        stack.stackPush(stack,5);
        stack.stackPush(stack,6);
        stack.stackPush(stack,7);
        stack.stackPush(stack,8);
        stack.stackPush(stack,9);
        stack.stackPush(stack,10);
        stack.stackPop(stack);
        stack.stackPop(stack);
        stack.stackPop(stack);
        stack.printStack(stack)
    }
}