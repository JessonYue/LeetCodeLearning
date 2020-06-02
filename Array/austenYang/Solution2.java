public class Solution2 {

    /**
     * 方案二
     *
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
        int n = 5;
        int sum = climbStairs(n);
        System.out.println(n + " 阶台阶共有:" + sum + "种走发");
    }
}
