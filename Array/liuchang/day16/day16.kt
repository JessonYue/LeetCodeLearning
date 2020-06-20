package net.study.kotlintest

/**
 * @author       刘畅
 * @createdate   2020/6/19
 * @describe
 */
class day16 {

    class StackQueue {
        var queue = CharArray(20);
        var front = 0;
        var rear = 0;

        fun stackPush(queue: StackQueue, data: Char) {
            queue.queue[queue.rear] = data;
            queue.rear++;
        }

        fun stackPop(queue: StackQueue) {
            queue.queue[queue.rear] = queue.queue[queue.rear - 1];
            queue.rear--;

        }

        fun printStack(queue: StackQueue) {
            for (i in 0 until queue.rear) {
                System.out.println(queue.queue[i]);
            }
        }

        fun isValid(queue: StackQueue): Boolean {
            for (i in 0 until queue.rear step 2) {
                if (queue.queue[i] == '(') {
                    if (queue.queue[i+1] != ')'){
                        return false
                    }
                }
                if (queue.queue[i] == '{') {
                    if (queue.queue[i+1] != '}'){
                        return false
                    }
                }
                if (queue.queue[i] == '[') {
                    if (queue.queue[i+1] != ']'){
                        return false
                    }
                }

            }
            return true;
        }


    }

    fun main(arg: Array<String>) {
        var stack: StackQueue = StackQueue();
        stack.stackPush(stack, '(');
        stack.stackPush(stack, ')');
        stack.stackPush(stack, '{');
        stack.stackPush(stack, '}');
        stack.stackPush(stack, '[');
        stack.stackPush(stack, ']');

    }
}