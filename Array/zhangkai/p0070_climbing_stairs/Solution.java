package com.github.leetcode.p0070_climbing_stairs;

/**
 * https://leetcode-cn.com/problems/two-sum/
 * <p>
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 注意：给定 n 是一个正整数。
 * <p>
 * 示例：
 * 输入： 3
 * 输出： 3
 * 解释： 有三种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶 + 1 阶
 * 2.  1 阶 + 2 阶
 * 3.  2 阶 + 1 阶
 * <p>
 * 时间复杂度在 O()
 *
 * 参考了：https://blog.csdn.net/qq_22379931/article/details/89060385
 */
class Solution {
    /**
     * --------------------我的代码--------------------
     */


    public int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        int p1 = 1;
        int p2 = 2;
        int temp = n;
        for (int i = 3; i <= n; i++) {
            temp = p1 + p2;
            p1 = p2;
            p2 = temp;
        }
        return temp;
    }
    //此种方法：超出时间限制
    /*public int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        return climbStairs(n - 1) + climbStairs(n - 2);
    }*/

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.climbStairs(45));//n=46时，结果会溢出
    }

    /**
     * --------------------别人的代码--------------------
     */

}