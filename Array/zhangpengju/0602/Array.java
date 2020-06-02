class Solution {

    @Test
    public void test(){
        int climb = climb(10);
        climb = dySort(10);
        System.out.println(climb);
    }


    /**
     * 使用递归调用 暴力法，把所有可能结构都加起来
     *
     * n过大时，会出现栈溢出
     *
     * @param n =1
     * @return
     */
    public int climb(int n) {
       return climb(0, n);
    }

    /**
     *
     * 分解成若干个最小单元处理，然后不断调用
     * @param i 为当前台阶数
     * @param n 为目标台阶数
     * @return
     */
    public int climb(int i, int n) {
        if (i > n) {//超出了，返回0
            return 0;
        }
        if (i == n) {//正好达到目标，标记为一种方式
            return 1;
        }
        return climb(i + 1, n) + climb(i + 2, n);
    }


    /**
     * 动态规划法
     *
     * 按照最小单位分 n阶台阶= n-1 阶台阶方法数 + n-2阶台阶方法数
     */
    public int dySort(int n){
        if (n == 1) {
            return 1;
        }
        int[] dp = new int[n + 1];
        dp[1] = 1; //有一种方式
        dp[2] = 2; //有两种方式
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
}