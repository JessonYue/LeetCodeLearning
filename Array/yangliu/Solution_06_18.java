import java.util.Stack;

public class Solution_06_18 {


    private int[] maxQueue;
    private int[] queue;
    private int queueHead;
    private int queueTail;
    private int maxQueueHead;
    private int maxQueueTail;

    public MaxQueue() {
        maxQueue = new int[10000];
        queue = new int[10000];
    }

    public int max_value() {
        if (maxQueueHead == maxQueueTail) return -1;
        return maxQueue[maxQueueHead];
    }

    public void push_back(int value) {
        queue[queueTail++] = value;
        while (maxQueueHead != maxQueueTail && maxQueue[maxQueueTail-1] < value) {
            maxQueueTail--;
        }
        maxQueue[maxQueueTail++] = value;
    }

    public int pop_front() {
        if (queueHead == queueTail) return -1;
        int i = queue[queueHead];
        if (i == maxQueue[maxQueueHead]) maxQueueHead++;
        queueHead++;
        return i;
    }
}
