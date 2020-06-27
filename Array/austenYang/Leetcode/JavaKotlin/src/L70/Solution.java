package L70;



public class Solution {

    /**
     * 方案二——递归法
     *
     * 一个人一次可以迈过一节楼梯, 或者两节楼梯
     * 问 N节楼梯有多少种走法?
     *
     * @param n
     * @return
     */
    public static int climbStairs1(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        return climbStairs1(n - 1) + climbStairs1(n - 2);
    }
    /**
     * 方案二
     *
     *
     * @param n
     * @return
     */
    public static int climbStairs2(int n) {
        if (n == 1) {
            return 1;
        }

        if (n == 2) {
            return 2;
        }
        int first = 1;
        int second = 2;
        int result = 0;
        for (int i = 3; i <= n; i++) {
            // f(n) = f(n-1) + f(n-2)
            // f(3) = f(2) + f(1)
            // f(4) = f(3) + f(2)
            // f(5) = f(4) + f(3)
            result = second + first;
            first = second;
            second = result;
        }

        return result;
    }


    public static void main(String[] args) {
        int n = 45;
        int sum1 = climbStairs1(n);
        int sum2 = climbStairs2(n);
        System.out.println(n + " 阶台阶共有:" + sum1 + "种走发");
        System.out.println(n + " 阶台阶共有:" + sum2 + "种走发");
    }
}
