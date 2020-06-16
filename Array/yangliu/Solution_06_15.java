import java.util.LinkedList;
import java.util.Queue;

public class Solution_06_15 {

class MyStack{
    Queue<Integer> queue;


    public MyStack() {
        queue = new LinkedList<>();
    }


    //通过一次循环 改变原来队列的顺序
    public void push(int x) {
        queue.add(x);
        for(int i = 1; i < queue.size(); i++)
            queue.add(queue.remove());
    }


    public int pop() {
        return queue.poll();
    }


    public int top() {
        return queue.peek();
    }


    public boolean empty() {
        return queue.size() == 0;
    }
}


}
