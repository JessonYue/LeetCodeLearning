package leetCode;

public class ClimbStairs {
    public int climbStairs(int n) {
        //解法1
//        return climbStairs(0,n);

        //解法2 记忆化递归
//        int[] mem = new int[n + 1];
//        return climbStairs(0, mem, n);

        //解法3 动态规划

        return climbStairsByDP(n);

    }


    private int climbStairsByDP(int n) {
        //terminal
        if (n == 1) {
            return 1;
        }
        int[] dp = new int[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }


    private int climbStairs(int from, int[] mem, int n) {
        //terminal
        if (from > n) {
            return 0;
        }
        if (from == n) {
            return 1;
        }
        if (mem[from] > 0) {
            return mem[from];
        }
        //process current  level
        mem[from] = climbStairs(from + 1, mem, n) + climbStairs(from + 2, mem, n);
        return mem[from];
        //drill  down
        //reset status

    }

    //递归调用
    private int climbStairs(int from, int n) {
        //terminal
        if (from > n) {
            return 0;
        }
        if (from == n) {
            return 1;
        }
        //process current  level
        return climbStairs(from + 1, n) + climbStairs(from + 2, n);
        //drill  down
        //reset status
    }
}
