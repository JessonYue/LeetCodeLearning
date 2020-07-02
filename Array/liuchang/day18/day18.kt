package net.study.kotlintest

/**
 * @author       刘畅
 * @createdate   2020/6/21
 * @describe
 */
class day18 {

    class MaxQueue {
        var data = IntArray(20, { it * it });
        var front = 0;
        var rear = 0;
        var maxsize = 0;

        fun isQueueFull(maxQueue: MaxQueue): Boolean {
            return maxQueue.rear == 20;
        }

        fun maxQueuePop_front(maxQueue: MaxQueue) {
            var num = maxQueue.data[maxQueue.front];
            maxQueue.front = (maxQueue.front) + 1;
            if (num >= maxQueue.maxsize) {
                maxQueue.maxsize = 0;
                for (i in maxQueue.front until maxQueue.rear) {
                    if (maxQueue.data[i] > maxQueue.maxsize) {
                        maxQueue.maxsize = maxQueue.data[i];
                    }
                }
            }
        }

        fun maxQueuePush_back(maxQueue: MaxQueue, data: Int) {
            if (isQueueFull(maxQueue)) {
                return;
            }
            if (data > maxQueue.maxsize) {
                maxQueue.maxsize = data;
            }
            maxQueue.data[maxQueue.rear] = data;
            maxQueue.rear++;
        }

        fun maxQueueMax_value(maxQueue: MaxQueue): Int {
            return maxQueue.maxsize;
        }
    }

    fun main(arg: Array<String>) {
        var maxQueue: MaxQueue = MaxQueue();
        maxQueue.maxQueuePush_back(maxQueue, 9);
        maxQueue.maxQueuePush_back(maxQueue, 2);
        maxQueue.maxQueuePush_back(maxQueue, 3);
        maxQueue.maxQueuePush_back(maxQueue, 4);
        maxQueue.maxQueuePush_back(maxQueue, 5);
        maxQueue.maxQueuePush_back(maxQueue, 6);
        maxQueue.maxQueuePush_back(maxQueue, 7);
        maxQueue.maxQueuePush_back(maxQueue, 8);
        maxQueue.maxQueuePush_back(maxQueue, 1);
        System.out.println("=====" + maxQueue.maxQueueMax_value(maxQueue));
        maxQueue.maxQueuePop_front(maxQueue);
        System.out.println("<>" + maxQueue.maxQueueMax_value(maxQueue));
    }

}