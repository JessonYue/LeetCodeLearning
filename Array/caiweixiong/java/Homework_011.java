import java.util.Queue;

public class Homework_011 {

    // 用队列实现栈，LeetCode第225题
    void homework_011_225() {
        MyStack obj = new MyStack();
        obj.push(4);
        int param_2 = obj.pop();
        System.out.println(param_2);
        int param_3 = obj.top();
        System.out.println(param_3);
        boolean param_4 = obj.empty();
        System.out.println(param_4);
    }
}
