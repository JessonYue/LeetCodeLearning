package net.study.kotlintest

/**
 * @author       刘畅
 * @createdate   2020/6/22
 * @describe
 */
class day19 {
    class MyQueue {
        var data = CharArray(20);
        var front = 0;
        var rear = 0;

        fun pushQueue(myQueue: MyQueue, data: String) {
            myQueue.data = data.toCharArray();
            myQueue.rear = myQueue.data.size;
        }

        fun removeDuplicates(myQueue: MyQueue) {
            var num = -1;
            for (k in 0 until myQueue.rear) {
//            for (int k = 0; k < myQueue.rear-1; ++k) {
                if (myQueue.data[k] == myQueue.data[k + 1] && k + 1 != myQueue.rear) {
                    num = k;
                    break;
                }
            }
            if (num != -1) {
                var temp: Char;
//                for (i = num; i < num + 2; ++i) {
                for (i in num until num + 2) {
                    temp = myQueue.data[num];
                    for (j in num until myQueue.rear - 1) {
//                    for (j = num; j < myQueue.rear - 1; ++j) {
                        myQueue.data[j] = myQueue.data[j + 1];
                    }
                    myQueue.data[myQueue.rear - 1] = temp;
                }
                myQueue.rear = myQueue.rear - 2;
                removeDuplicates(myQueue);
            }
        }


    }

    fun main(arg: Array<String>) {
        var myQueue: MyQueue = MyQueue();
        myQueue.pushQueue(myQueue, "abbaca");
        for (i in 0 until myQueue.rear) {
            System.out.println("=====" + myQueue.data[i]);
        }
        myQueue.removeDuplicates(myQueue);
        for (i in 0 until myQueue.rear) {
            System.out.println("<===>" + myQueue.data[i]);
        }
    }
}