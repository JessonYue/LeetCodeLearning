import com.sun.org.apache.xerces.internal.util.XMLInputSourceAdaptor;

public class Solution3 {

    /**
     * 方案二——递归法
     *
     * 一个人一次可以迈过一节楼梯, 或者两节楼梯
     * 问 N节楼梯有多少种走法?
     *
     * @param n
     * @return
     */
    public static int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        return climbStairs(n - 1) + climbStairs(n - 2);
    }

    public static void main(String[] args) {
        int n = 45;
        int sum = climbStairs(n);
        System.out.println(n + " 阶台阶共有:" + sum + "种走发");
    }
}
